#ifndef _GHRENDR_EVENT_H_
#define _GHRENDR_EVENT_H_

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

#define SHIFT(x) (1 << x)
enum class EventCategory {
	None = 0,

	EventCategoryApp		 = SHIFT(0),
	EventCategoryInput		 = SHIFT(1),
	EventCategoryKeyboard	 = SHIFT(2),
	EventCategoryMouse		 = SHIFT(3),
	EventCategoryMouseButton = SHIFT(4),
	EventCategorySecret		 = SHIFT(5)
};

class Event {
	friend class dispatcher;
protected:
	bool m_Handled = false;
public:
	virtual EventType getEventType() const = 0;
	virtual int getCategory() const = 0;
};

#endif