#pragma once

#include "Event.h"

namespace GH {
	class WindowClosedEvent : public Event {
	public:
		WindowClosedEvent() = default;
		EVENT_TYPE(WindowClose);
		EVENT_CATEGORY(EventCategoryApp);
	};
}