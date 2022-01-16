#pragma once

#include <glad/glad.h>
#include "Window.h"
#include "../Platform/Windows/Win32Window.h"
#include "../Events/Event.h"
#include "../Events/KeyboardEvents.h"
#include "Core.h"

namespace GH {
	class Application {
	private:
		Scope<Window> m_Window;
		Win32Window m_WindowHandle;
		static Application* instance;
	public:
		Application();

		void onEvent(Event& e);
		bool onKeyPressed(KeyboardPressedEvent& e);
		bool onKeyReleased(KeyboardReleasedEvent& e);
		Window& getWindow() { return *m_Window; }

		void run();

		static Application& get() { return *instance; }
	};
}
