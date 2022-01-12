#include "WinWindow.h"
#include "../../Error/ghassert.hpp"
#include <iostream>

namespace GH {
	void WinWindow::Init()  {
		bool success = glfwInit();

		GH_ASSERT(success, "Could not initialize GLFW");

		this->m_Data.height = properties.height;
		this->m_Data.height = properties.width;
		this->m_Data.title = properties.title;
	}

	void WinWindow::createWindow() {
		this->m_Window = glfwCreateWindow(properties.width, properties.height, properties.title, nullptr, nullptr);
		glfwSetWindowPos(this->m_Window, 50, 50);
		GH_ASSERT(this->m_Window, "Could not initialize GLFW");
	}

	WinWindow::~WinWindow() {
		glfwDestroyWindow(this->m_Window);
	}

}
