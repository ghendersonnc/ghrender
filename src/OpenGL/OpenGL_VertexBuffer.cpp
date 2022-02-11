#include "OpenGL_VertexBuffer.h"

namespace GH {
	GLVertexBuffer::GLVertexBuffer(GLenum target, float* vertices, GLsizeiptr size, GLenum usage) {
		m_Target = target;
		glGenBuffers(1, &m_ID);
		glBindBuffer(target, m_ID);
		glBufferData(target, size, vertices, usage);
	}

	void GLVertexBuffer::update(GLsizeiptr size, const void* vertices) {
		glBufferSubData(m_Target, 0, size, vertices);
	}

}