#pragma once

#include "../../Core/Window.h"
#include <GLFW/glfw3.h>
namespace GH {
	class WinWindow : public Window {
	private:
		GLFWwindow* m_Window;
		struct WindowData {
			char* title;
			unsigned short width;
			unsigned short height;
		};
		WindowData m_Data;
	public:


		WinWindow() = default;

		void Init() override;
		void createWindow() override;
		//void setEventCallback(const EventCallbackFunc& callback) override;
		GLFWwindow* getWindow() { return m_Window; };

		virtual ~WinWindow();

	};
}

