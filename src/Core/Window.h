#pragma once

#include "../Events/Event.h"
// Abstract platform based Window class
namespace GH {

	class Window {
	private:
		struct WindowProperties {
			char* title = "ghrendr";
			unsigned short width = 1600;
			unsigned short height = 900;
		};

	protected:
		WindowProperties properties;

	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual void Init() = 0;
		virtual void setEventCallback(const EventCallbackFunc& callback) = 0;
		virtual ~Window() {};
	};
}

