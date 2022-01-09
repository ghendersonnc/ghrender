#include "WinWindow.h"
#include <assert.h>

//
// using assert as placeholder till i implement assert macro
//
// the glfw window hints will be moved
//
WinWindow::WinWindow() {
	bool success = glfwInit();
	assert(success && "Could not initialize GLFW");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(300, 300, "PLACEHOLDER", nullptr, nullptr);

	assert(m_Window && "Could not create a window context");
}
