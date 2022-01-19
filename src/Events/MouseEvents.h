#pragma once

#include "Event.h"
#include "../Core/MouseCodes.h"

#include <sstream>

namespace GH {
	class MouseButtonEvent : public Event {
	public:
		MouseCode getMouseCode() const { return m_MouseCode; }

		EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton);
	protected:
		MouseButtonEvent(const MouseCode mouseCode) : m_MouseCode(mouseCode) {}

		MouseCode m_MouseCode;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(const MouseCode mouseCode) : MouseButtonEvent(mouseCode) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MousePressedEvent: " << m_MouseCode;
			return ss.str();
		}

		EVENT_TYPE(MouseButtonPressed);

	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(const MouseCode mouseButton) : MouseButtonEvent(mouseButton) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseReleasedEvent: " << m_MouseCode;
			return ss.str();
		}

		EVENT_TYPE(MouseButtonRelease);
	};
}