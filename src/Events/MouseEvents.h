#pragma once

#include "Event.h"
#include "../Core/MouseCodes.h"

namespace GH {

	class MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(const float x, const float y) : m_MouseXPos(x), m_MouseYPos(y) {}

		float getXPos() const { return m_MouseXPos; }
		float getYPos() const { return m_MouseYPos; }

		EVENT_TYPE(MouseMove);
		EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput);

		// Debugging
		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseXPos << ", " << m_MouseYPos;
			return ss.str();
		}

	private:
		float m_MouseXPos;
		float m_MouseYPos;
	};

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

		// Debugging
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