#pragma once

// Win32 refers to _WIN32. It does not mean it is 32-bit only

#include "../../Core/Window.h"
#include "../../Core/KeyCodes.h"
#include <GLFW/glfw3.h>
namespace GH {
	class Win32Window : public Window {
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
		Win32Window() = default;
		Win32Window(const WindowProperties& properties);

		virtual void Init(const WindowProperties& properties);
		void setEventCallback(const EventCallbackFunc& callback) override { this->m_Data.eventCallback = callback; };
		bool isKeyPressed(const KeyCode key);
		void update();
		virtual void* getContextWindow() { return m_Window; };

		virtual ~Win32Window();

	};
}
