#pragma once

#include "../Events/Event.h"
#include "Core.h"
// Abstract platform based Window class
namespace GH {
	struct WindowProperties {
		char* title = "ghrendr";
		unsigned short width = 1600;
		unsigned short height = 900;
	};

	class Window {
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual void setEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void* getContextWindow() = 0;
		static Scope<Window> create(const WindowProperties& properties = WindowProperties());
		virtual ~Window() {};
	};
}
