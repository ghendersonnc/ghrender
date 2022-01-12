#include "Application.h"

#include <iostream>

#include "../Platform/Windows/WinWindow.h"
#include "../Events/Event.h"
#include "../Events/KeyboardEvents.h"
#include "../Error/ghassert.hpp"
#include "KeyCodes.h"

namespace GH {
	void Application::run() {
	#ifdef _WIN32
		WinWindow m_WindowHandle;
	#else
		GH_ASSERT(0, "Unknown or unsupported platform");
	#endif
		m_WindowHandle.Init();
		m_WindowHandle.createWindow();
		GLFWwindow* nativeWindow = m_WindowHandle.getWindow();
		glfwMakeContextCurrent(nativeWindow);

		// TODO: Create OpenGL platform
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			exit(EXIT_FAILURE);
		}
		KeyboardPressedEvent A(Key::A, 0);

		std::cout << A.ToString() << std::endl;
		while (!glfwWindowShouldClose(nativeWindow)) {
			glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(nativeWindow);
			glfwPollEvents();
		}

		glfwTerminate();
	}

}