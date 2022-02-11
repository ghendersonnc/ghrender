#include "OpenGL_VertexArray.h"

namespace GH {
	GLVertexArray::GLVertexArray() {
		glGenVertexArrays(1, &m_ID);
		glBindVertexArray(m_ID);
	}

	void GLVertexArray::linkBuffer(GLVertexBuffer& vbo, const unsigned int index, const int size, const int stride, const int offset) {
		vbo.bind();
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
		glEnableVertexAttribArray(index);

		vbo.unbind();
	}
}
