#include "Application.h"

#include <iostream>

#include "KeyCodes.h"
#include "../Error/ghassert.hpp"
#include "Input.h"

namespace GH {
	Application* Application::instance = nullptr;
	Application::Application() {
		
		GH_ASSERT(!instance, "Application exists.");
		instance = this;
		this->m_Window = Window::create(WindowProperties());
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

	// Likely only in Application.cpp temporarily
	void Application::onEvent(Event& e) {
		Dispatcher dispatcher(e);

		dispatcher.dispatch<KeyboardPressedEvent>(BIND_EVENT(Application::onKeyPressed));
		dispatcher.dispatch<KeyboardReleasedEvent>(BIND_EVENT(Application::onKeyReleased));
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
}
