#pragma once
#include <glad/glad.h>
#include "OpenGL_VertexBuffer.h"
namespace GH {
	class GLVertexArray {
	private:
		unsigned int m_ID;
	public:
		GLVertexArray();
		void linkBuffer(GLVertexBuffer& vbo, const unsigned int index, const int size, const int stride, const int offset);
		void bind() { glBindVertexArray(m_ID); }
		void unbind() {	glBindVertexArray(0);};
		void destroy() { glDeleteVertexArrays(1, &m_ID); }

	};
}