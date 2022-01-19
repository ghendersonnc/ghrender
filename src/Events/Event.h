#pragma once

#include <string>
#include <functional>

#define BIT(x) (1 << x)
// Events are blocking

namespace GH {
	enum class EventType {
		None = 0,
		// Window events
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,

		// App events?
		AppUpdate, AppRender,

		// Key events. KeyTyped is essentially KeyPress and KeyRelease put together; pressing and releasing the key as one event
		KeyPress, KeyRelease, KeyTyped,

		// Mouse events
		MouseButtonPressed, MouseButtonRelease, MouseMove, MouseScroll,

		Secret
	};

	enum EventCategory {
		None = 0,

		EventCategoryApp = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),
		EventCategorySecret = BIT(5)
	};

#define EVENT_TYPE(Type) static EventType getStaticType() { return EventType::Type; }\
		virtual EventType getEventType() const override { return getStaticType(); }\
		virtual const char* getName() const override { return #Type; }

#define EVENT_CATEGORY(Cat) virtual int getCategoryFlags() const override { return Cat; }

	class Event {
		friend class Dispatcher;
	public:
		bool handled = false;
		virtual EventType getEventType() const = 0;
		// Debug purposes
		virtual const char* getName() const = 0;

		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

	};

	class Dispatcher {
	private:
		Event& m_Event;

	public:
		Dispatcher(Event& event) : m_Event(event) {}

		template<typename T, typename F>
		bool dispatch(const F& funct) {
			if (m_Event.getEventType() == T::getStaticType()) {
				m_Event.handled |= funct(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	};
}
