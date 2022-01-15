#pragma once

// Win32 refers to _WIN32. It does not mean it is 32-bit only

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

			EventCallbackFunc eventCallback;
		};
		WindowData m_Data;
	public:

		WinWindow() = default;

		void Init() override;
		void setEventCallback(const EventCallbackFunc& callback) override { this->m_Data.eventCallback = callback; };
		GLFWwindow* getWindow() { return m_Window; };

		virtual ~WinWindow();

	};
}

