#pragma once

#include "../../Core/Application.h"
#include "../../Core/Input.h"
#include <GLFW/glfw3.h>

namespace GH {
	bool Input::isKeyPress(const KeyCode key) {
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getContextWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
}