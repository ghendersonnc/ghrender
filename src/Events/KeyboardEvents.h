#pragma once

#include "Event.h"
namespace GH {
	// Abstract keyboard "event" class
	class KeyboardEvent : public Event {
	public:
		inline int getKeyCode() const { return m_KeyCode; }

		EVENT_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	protected:
		KeyboardEvent(int keyCode) : m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	// This includes pressing and holding (repeat events) a key
	class KeyboardPressedEvent : public KeyboardEvent {
	private:
		int m_RepeatCount;
	public:
		KeyboardPressedEvent(int keyCode, int repeatCount) : KeyboardEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int getRepeatCount() { return m_RepeatCount; }

		EVENT_TYPE(KeyPress);

	};

	class KeyboardReleasedEvent : public KeyboardEvent {
		KeyboardReleasedEvent(int keyCode) : KeyboardEvent(keyCode) {}

		EVENT_TYPE(KeyRelease);
	};
}