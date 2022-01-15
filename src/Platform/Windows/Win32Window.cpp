#include <iostream>

#include "Win32Window.h"
#include "../../Error/ghassert.hpp"
#include "../../Events/KeyboardEvents.h"

namespace GH {
	void WinWindow::Init()  {
		bool success = glfwInit();

		GH_ASSERT(success, "Could not initialize GLFW");

		this->m_Data.height = properties.height;
		this->m_Data.height = properties.width;
		this->m_Data.title = properties.title;
		this->m_Window = glfwCreateWindow(properties.width, properties.height, properties.title, nullptr, nullptr);
		glfwSetWindowPos(this->m_Window, 50, 50);
		GH_ASSERT(this->m_Window, "Could not initialize GLFW");

		glfwSetWindowUserPointer(m_Window, &this->m_Data);

		// glfw callbacks
		glfwSetKeyCallback(this->m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			if (action == GLFW_PRESS) {
				KeyboardPressedEvent event(key, 0);
				data.eventCallback(event);
			}
			else if (action == GLFW_RELEASE) {
				KeyboardReleasedEvent event(key);
				data.eventCallback(event);
			}
			else if (action == GLFW_REPEAT) {
				KeyboardPressedEvent event(key, 1);
				data.eventCallback(event);
			}

		});

	}

	WinWindow::~WinWindow() {
		glfwDestroyWindow(this->m_Window);
	}

}
