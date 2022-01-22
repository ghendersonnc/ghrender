#pragma once

#include <glad/glad.h>
#include "Window.h"
#include "../Platform/Windows/Win32Window.h"
#include "../Events/Event.h"
#include "../Events/KeyboardEvents.h"
#include "../Events/MouseEvents.h"
#include "../Events/WindowEvents.h"
#include "Core.h"

namespace GH {
	class Application {
	private:
		Scope<Window> m_Window;
		static Application* s_Instance;
		bool m_Running = false;
	public:
		Application();

		void onEvent(Event& e);
		bool onWindowClosed(WindowClosedEvent& e);
		bool onKeyPressed(KeyboardPressedEvent& e);
		bool onKeyReleased(KeyboardReleasedEvent& e);
		bool onMousePressed(MouseButtonPressedEvent& e);
		bool onMouseReleased(MouseButtonReleasedEvent& e);
		bool onMouseMoved(MouseMovedEvent& e);
		Window& getWindow() { return *m_Window; }

		void run();

		static Application& get() { return *s_Instance; }
	};
}
