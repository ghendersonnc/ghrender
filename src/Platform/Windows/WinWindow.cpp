#include "WinWindow.h"
#include "../../Error/ghassert.h"
#include <iostream>




void WinWindow::Init()  {
	bool success = glfwInit();

	GH_ASSERT(success, "Could not initialize GLFW");
}

void WinWindow::createWindow() {
	this->m_Window = glfwCreateWindow(properties.width, properties.height, properties.title, nullptr, nullptr);
	glfwSetWindowPos(this->m_Window, 50, 50);
	GH_ASSERT(this->m_Window, "Could not initialize GLFW");
}
