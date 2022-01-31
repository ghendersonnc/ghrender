#include <iostream>

#include "Win32Window.h"
#include "../../Error/ghassert.hpp"
#include "../../Events/KeyboardEvents.h"
#include "../../Events/MouseEvents.h"
#include "../../Events/WindowEvents.h"
#include "../../Core/Input.h"
namespace GH {
	bool Win32Window::isKeyPressed(const KeyCode key) {
		auto state = glfwGetKey(m_Window, static_cast<int32_t>(key));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	Win32Window::Win32Window(const WindowProperties& properties) {
		Init(properties);
	}

	void Win32Window::Init(const WindowProperties& properties)  {
		bool success = glfwInit();

		GH_ASSERT(success, "Could not initialize GLFW");

		m_Data.height = properties.height;
		m_Data.width = properties.width;
		m_Data.title = properties.title;
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		m_Window = glfwCreateWindow(properties.width, properties.height, properties.title, nullptr, nullptr);
		glfwSetWindowPos(m_Window, 50, 50);
		GH_ASSERT(m_Window, "Could not initialize GLFW Window context");

		glfwSetWindowUserPointer(m_Window, &m_Data);

		// glfw callbacks
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
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

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			if (action == GLFW_PRESS) {
				MouseButtonPressedEvent event(button);
				data.eventCallback(event);
			}
			else if (action == GLFW_RELEASE) {
				MouseButtonReleasedEvent event(button);
				data.eventCallback(event);
			}
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos){
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xpos, (float)ypos);
			data.eventCallback(event);

		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowClosedEvent event;
			data.eventCallback(event);
		});

	}

	void Win32Window::update() {
		glfwPollEvents();

		// Currently temporary and will be relevant to the opengl context.
		glfwSwapBuffers(m_Window);
	}

	Win32Window::~Win32Window() {
		glfwDestroyWindow(m_Window);
	}

}
