#pragma once

#include "Event.h"
#include "../Core/KeyCodes.h"

#include <sstream>

namespace GH {
	// Abstract keyboard "event" class
	class KeyboardEvent : public Event {
	public:
		inline int getKeyCode() const { return m_KeyCode; }

		EVENT_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	protected:
		KeyboardEvent(const KeyCode keyCode) : m_KeyCode(keyCode) {}

		KeyCode m_KeyCode;
	};

	// This includes pressing and holding (repeat events) a key
	class KeyboardPressedEvent : public KeyboardEvent {
	private:
		uint16_t m_RepeatCount;
	public:
		KeyboardPressedEvent(const KeyCode keyCode, int repeatCount) 
			: KeyboardEvent(keyCode), m_RepeatCount(repeatCount) {}

		uint16_t getRepeatCount() { return m_RepeatCount; }

		EVENT_TYPE(KeyPress);

		// Debugging
		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyboardPressedEvent: " << this->m_KeyCode << " (" << this->m_RepeatCount << " repeats)";
			return ss.str();
		}

	};

	class KeyboardReleasedEvent : public KeyboardEvent {
	public:
		KeyboardReleasedEvent(const KeyCode keyCode) : KeyboardEvent(keyCode) {}

		EVENT_TYPE(KeyRelease);

		// Debugging
		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyboardReleasedEvent: " << this->m_KeyCode;
			return ss.str();
		}
	};

	class KeyboardTypedEvent : public KeyboardEvent {
	public:
		KeyboardTypedEvent(const KeyCode keyCode) : KeyboardEvent(keyCode) {}

		EVENT_TYPE(KeyTyped);

		// Debugging
		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyboardTypedEvent: " << this->m_KeyCode;
			return ss.str();
		}
	};
}
