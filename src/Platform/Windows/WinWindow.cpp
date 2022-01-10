#include "WinWindow.h"
#include "../../Error/ghassert.h"

//
// the glfw window hints will be moved
//
WinWindow::WinWindow() {
	bool success = glfwInit();
	
	GH_ASSERT(!success, "Could not initialize GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(300, 300, "PLACEHOLDER", nullptr, nullptr);

	GH_ASSERT(m_Window, "GLFW could not create a window context");
}
