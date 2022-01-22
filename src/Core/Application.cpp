#include "Application.h"

#include <iostream>

#include "KeyCodes.h"
#include "../Error/ghassert.hpp"
#include "Input.h"



namespace GH {
	Application* Application::s_Instance = nullptr;
	Application::Application() { GH_ASSERT(!s_Instance, "Application exists.");
		s_Instance = this;
		m_Window = Window::create(WindowProperties());
		m_Window->setEventCallback(BIND_EVENT(Application::onEvent));
	}

	// TODO: Maybe "sandbox" this 
	void Application::run() {
		m_Running = true;
		// TODO: Modularize OpenGL and GLFW updates

		GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getContextWindow());
		glfwMakeContextCurrent(window);


		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			exit(EXIT_FAILURE);
		}


		while (m_Running) {
			glClearColor(0.43f, 0.03f, 0.76f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			

			m_Window->update();
		}
		
	}

	// Below functions are likely only in Application.cpp temporarily and will be per context
	void Application::onEvent(Event& e) {
		Dispatcher dispatcher(e);

		dispatcher.dispatch<KeyboardPressedEvent>(BIND_EVENT(Application::onKeyPressed));
		dispatcher.dispatch<KeyboardReleasedEvent>(BIND_EVENT(Application::onKeyReleased));
		dispatcher.dispatch<MouseButtonPressedEvent>(BIND_EVENT(Application::onMousePressed));
		dispatcher.dispatch<MouseButtonReleasedEvent>(BIND_EVENT(Application::onMouseReleased));
		dispatcher.dispatch<MouseMovedEvent>(BIND_EVENT(Application::onMouseMoved));
		dispatcher.dispatch<WindowClosedEvent>(BIND_EVENT(Application::onWindowClosed));
	}

	bool Application::onWindowClosed(WindowClosedEvent& e) {
		m_Running = false;
		std::cout << "bye" << std::endl;
		glfwTerminate();

		return true;
	}

	bool Application::onKeyPressed(KeyboardPressedEvent& e) {

		bool isControl = Input::isKeyPress(Key::LeftControl);

		switch (e.getKeyCode()) {
		case Key::Q:
			WindowClosedEvent close;
			Dispatcher d(close);
			d.dispatch<WindowClosedEvent>(BIND_EVENT(Application::onWindowClosed));
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

	bool Application::onMouseMoved(MouseMovedEvent& e) {

		std::cout << e.toString() << std::endl;

		return true;
	}
}
