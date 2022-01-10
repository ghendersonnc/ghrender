#include "Application.h"

#include <iostream>



//#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <imgui.h>

#include <stb_image/stb_image.h>
#include "../Platform/Windows/WinWindow.h"

void Application::run() {
	WinWindow m_WindowHandle;
	m_WindowHandle.Init();
	m_WindowHandle.createWindow();
	glfwMakeContextCurrent(m_WindowHandle.m_Window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		exit(EXIT_FAILURE);
	}

	IMGUI_CHECKVERSION();

	while (!glfwWindowShouldClose(m_WindowHandle.m_Window)) {
		glfwSwapBuffers(m_WindowHandle.m_Window);
		glfwPollEvents();
	}

	glfwTerminate();
}