#pragma once
#include <glad/glad.h>

namespace GH {
	class GLVertexBuffer {
	private:
		unsigned int m_ID;
		GLenum m_Target;
	public:
		GLVertexBuffer(GLenum target, float* vertices, GLsizeiptr size, GLenum usage);
		void update(GLsizeiptr size, const void* vertices);
		void bind() { glBindBuffer(m_Target, m_ID); }
		void unbind() { glBindBuffer(m_Target, 0); }
		void destroy() { glDeleteBuffers(1, &m_ID); }
	};
}