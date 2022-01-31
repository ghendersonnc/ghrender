#include "OpenGL_Shader.h"

namespace GH {
	GLShader::GLShader(const std::string vertexShaderPath, const std::string fragmentShaderPath) {
		m_VertexSrc = readShaderSrc(vertexShaderPath);
		m_FragmentSrc = readShaderSrc(fragmentShaderPath);

		uint32_t vertexShader;
		uint32_t fragmentShader;

		vertexShader = compileShader(GL_VERTEX_SHADER, m_VertexSrc);
		fragmentShader = compileShader(GL_FRAGMENT_SHADER, m_FragmentSrc);

		m_ID = glCreateProgram();
		glAttachShader(m_ID, vertexShader); glAttachShader(m_ID, fragmentShader);
		glLinkProgram(m_ID);
		glValidateProgram(m_ID);

		glDeleteShader(vertexShader); glDeleteShader(fragmentShader);

		// debug
		int validated;
		glGetProgramiv(m_ID, GL_VALIDATE_STATUS, &validated);
		if (!validated) {
			char log[1024];
			int l;

			glGetProgramInfoLog(m_ID, 1024, &l, log);
			std::cerr << log << std::endl;

			GH_ASSERT(false, "Shader program not validated.");
		}
	}

	void GLShader::use() {
		glUseProgram(m_ID);
	}

	void GLShader::destroy() {
		glDeleteProgram(m_ID);
	}

	void GLShader::setVec2(const char* uniformName, const glm::vec2& vector) {
		glUniform2fv(glGetUniformLocation(m_ID, uniformName), 1, glm::value_ptr(vector));
	}

	void GLShader::setVec3(const char* uniformName, const glm::vec3& vector) {
		glUniform3fv(glGetUniformLocation(m_ID, uniformName), 1, glm::value_ptr(vector));
	}

	void GLShader::setVec4(const char* uniformName, const glm::vec4& vector) {
		glUniform4fv(glGetUniformLocation(m_ID, uniformName), 1, glm::value_ptr(vector));
	}

	void GLShader::setMat4(const char* uniformName, glm::mat4& matrix) {
		glUniformMatrix4fv(glGetUniformLocation(m_ID, uniformName), 1, GL_FALSE, glm::value_ptr(matrix));
	}
}