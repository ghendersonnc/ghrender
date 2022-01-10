#include "Application.h"

#include <iostream>

#include "../Platform/Windows/WinWindow.h"

#include "../Error/ghassert.h"

void Application::run() {
#ifdef _WIN32
	WinWindow m_WindowHandle;
#else
	GH_ASSERT(0, "Unknown or unsupported platform");
#endif
	m_WindowHandle.Init();
	m_WindowHandle.createWindow();
	glfwMakeContextCurrent(m_WindowHandle.m_Window);

	// TODO: Create OpenGL platform
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		exit(EXIT_FAILURE);
	}


	while (!glfwWindowShouldClose(m_WindowHandle.m_Window)) {
		glfwSwapBuffers(m_WindowHandle.m_Window);
		glfwPollEvents();
	}

	glfwTerminate();
}