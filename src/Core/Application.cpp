#include "Application.h"

#include <iostream>

#include "../Platform/Windows/Win32Window.h"
#include "../Events/Event.h"
#include "../Events/KeyboardEvents.h"
#include "KeyCodes.h"
#include "../Error/ghassert.hpp"
#include "KeyCodes.h"

namespace GH {
	void onEvent(Event& e);
	bool onKeyPressed(KeyboardPressedEvent& e);
	bool onKeyReleased(KeyboardReleasedEvent& e);
	void Application::run() {
	#ifdef _WIN32
		WinWindow m_WindowHandle;
	#else
		GH_ASSERT(0, "Unknown or unsupported platform");
	#endif
		m_WindowHandle.Init();


		m_WindowHandle.setEventCallback(onEvent);

		GLFWwindow* nativeWindow = m_WindowHandle.getWindow();
		glfwMakeContextCurrent(nativeWindow);

		// TODO: Create OpenGL platform
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			exit(EXIT_FAILURE);
		}
		
		while (!glfwWindowShouldClose(nativeWindow)) {
			glClearColor(0.43f, 0.03f, 0.76f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(nativeWindow);
			glfwPollEvents();
		}

		glfwTerminate();
	}

	// Likely only in Application.cpp temporarily
	void onEvent(Event& e) {
		Dispatcher dispatcher(e);

		dispatcher.dispatch<KeyboardPressedEvent>(onKeyPressed);
		dispatcher.dispatch<KeyboardReleasedEvent>(onKeyReleased);
	}

	bool onKeyPressed(KeyboardPressedEvent& e) {
		KeyCode code = e.getKeyCode();

		switch (code) {
		case Key::Escape:
			glfwTerminate();
			exit(EXIT_SUCCESS);
			break;
		}
		
		return true;
	}

	bool onKeyReleased(KeyboardReleasedEvent& e) {
		
		return true;
	}
}

