#include "Application.h"

#include <iostream>

#include "KeyCodes.h"
#include "../Error/ghassert.hpp"

#include <glm/glm.hpp>
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

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 330");
		
		bool coolStuff = false;

		while (m_Running) {
			glClearColor(0.43f, 0.03f, 0.76f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// basic ImGui stuff
			{
				ImGui_ImplOpenGL3_NewFrame();
				ImGui_ImplGlfw_NewFrame();
				ImGui::NewFrame();
				ImGui::SetNextWindowSize(ImVec2(400.0f, 100.0f));
				ImGui::SetNextWindowPos(ImVec2(600.0f, 400.0f));
				ImGui::Begin("hi");
				ImGui::Text("For whatever reason you cloned and built this.\nHere is a quit button");
				if (ImGui::Button("Quit")) {
					WindowClosedEvent close;
					Dispatcher d(close);
					d.dispatch<WindowClosedEvent>(BIND_EVENT(Application::onWindowClosed));
				}
				ImGui::End();
			
				ImGui::Render();
				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			}

			m_Window->update();
		}
		
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

	}

	// Below functions are likely only in Application.cpp temporarily and will be per context
	void Application::onEvent(Event& e) {
		Dispatcher dispatcher(e);

		dispatcher.dispatch<KeyboardPressedEvent>(BIND_EVENT(Application::onKeyPressed));
		dispatcher.dispatch<KeyboardReleasedEvent>(BIND_EVENT(Application::onKeyReleased));
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

}
