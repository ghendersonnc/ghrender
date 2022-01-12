#pragma once

#include <string>
#include <functional>

// Events are blocking

enum class EventType {
	None = 0,
	// Window events
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,

	// App events?
	AppUpdate, AppRender,

	// Key events
	KeyPress, KeyRelease,

	// Mouse events
	MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll,

	Secret
};

#define BIT(x) (1 << x)
enum class EventCategory {
	None = 0,

	EventCategoryApp		 = BIT(0),
	EventCategoryInput		 = BIT(1),
	EventCategoryKeyboard	 = BIT(2),
	EventCategoryMouse		 = BIT(3),
	EventCategoryMouseButton = BIT(4),
	EventCategorySecret		 = BIT(5)
};

class Event {
	friend class Dispatcher;
public:
	GHbool handled = false;
	virtual EventType getEventType() const  = 0;
	virtual int getCategory() const			= 0;
	// Debug purposes
	virtual const char* getName() const		= 0;

	virtual std::string ToString() const { return getName(); }
};

#define EVENT_TYPE(t) static EventType getStaticType() { return EventType::t; } \
	virtual EventType getEventType() const override { return getStaticType(); } \
	virtual const char* getName() const override { return #t; };

class Dispatcher {
private:
	Event& m_Event;
public:
	Dispatcher(Event& event) : m_Event(event) {}

	template<typename T, typename F>
	GHbool dispatch(const F& funct) {
		if (m_Event.getEventType() == T::getStaticType()) {
			m_Event.handled |= funct(static_cast<T&>(m_Event));
			return true;
		}
		return false;
	}
};