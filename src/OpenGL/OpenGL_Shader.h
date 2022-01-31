#pragma once


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include "../Error/ghassert.hpp"

#include <glad/glad.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
using std::filesystem::current_path;
namespace GH {
	class GLShader {
	private:
		std::string m_VertexSrc;
		std::string m_FragmentSrc;
		unsigned int m_ID;

		std::string readShaderSrc(const std::string shaderPath) {
			std::ifstream shaderCode(shaderPath);
			auto ss = std::ostringstream{};
			if (!shaderCode.is_open()) {
				std::cerr << shaderPath << " does not exist" << std::endl;
				GH_ASSERT(false, "Cannot open file");
			}

			ss << shaderCode.rdbuf();
			shaderCode.close();
			return ss.str();
		}

		unsigned int compileShader(GLenum type, const std::string shaderSource) {
			const char* src = shaderSource.c_str();
			unsigned int id = glCreateShader(type);
			glShaderSource(id, 1, &src, nullptr);
			glCompileShader(id);

			int result;
			glGetShaderiv(id, GL_COMPILE_STATUS, &result);

			if (!result) {
				int queryLength;
				glGetShaderiv(id, GL_INFO_LOG_LENGTH, &queryLength);
				char* errorLog = new char[queryLength * sizeof(char)];

				glGetShaderInfoLog(id, queryLength, &queryLength, errorLog);
				std::cerr << "Failed to compile "
					<< ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment")
					<< " shader: "
					<< errorLog << std::endl;
				
				glDeleteShader(id);
				delete[] errorLog;
				GH_ASSERT(false, "Shader compilation failure");

			}
			return id;
		}
	public:

		// Only vertex and fragment shaders
		// Geometry shaders are unnecessary
		// Compute and tesselation are impossible as I am using OpenGL 3.3

		GLShader(const std::string vertexShaderPath, const std::string fragmentShaderPath);
		void use();
		void setVec2(const char* uniformName, const glm::vec2& vector);
		void setVec3(const char* uniformName, const glm::vec3& vector);
		void setVec4(const char* uniformName, const glm::vec4& vector);
		void setMat4(const char* uniformName, glm::mat4& matrix);
		void destroy();
		unsigned int getID() { return m_ID; }
	};
}