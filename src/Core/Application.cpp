#include "Application.h"

#include <iostream>

#include "KeyCodes.h"
#include "../Error/ghassert.hpp"
#include "Input.h"

namespace GH {
	Application* Application::s_Instance = nullptr;
	Application::Application() {
		
		GH_ASSERT(!s_Instance, "Application exists.");
		s_Instance = this;
		m_Window = Window::create(WindowProperties());
		m_Window->setEventCallback(BIND_EVENT(Application::onEvent));
	}

	void Application::run() {
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getContextWindow());
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			exit(EXIT_FAILURE);
		}

		while (!glfwWindowShouldClose(window)) {
			glClearColor(0.43f, 0.03f, 0.76f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
	}

	// Below functions are likely only in Application.cpp temporarily
	// I plan on them being per "widget"
	void Application::onEvent(Event& e) {
		Dispatcher dispatcher(e);

		dispatcher.dispatch<KeyboardPressedEvent>(BIND_EVENT(Application::onKeyPressed));
		dispatcher.dispatch<KeyboardReleasedEvent>(BIND_EVENT(Application::onKeyReleased));
		dispatcher.dispatch<MouseButtonPressedEvent>(BIND_EVENT(Application::onMousePressed));
		dispatcher.dispatch<MouseButtonReleasedEvent>(BIND_EVENT(Application::onMouseReleased));
	}
	
	bool Application::onKeyPressed(KeyboardPressedEvent& e) {
		
		bool isControl = Input::isKeyPress(Key::LeftControl);

		switch (e.getKeyCode()) {
		case Key::Q:
			if (isControl) exit(EXIT_SUCCESS);
			break;
		}

		return true;
	}

	bool Application::onKeyReleased(KeyboardReleasedEvent& e) {
		
		return true;
	}

	bool Application::onMousePressed(MouseButtonPressedEvent& e) {

		return true;
	}

	bool Application::onMouseReleased(MouseButtonReleasedEvent& e) {
		return true;
	}
}
