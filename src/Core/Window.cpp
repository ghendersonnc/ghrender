#include "Window.h"
#include "../Error/ghassert.hpp"

#ifdef _WIN32
#include "../Platform/Windows/Win32Window.h"
#endif

namespace GH {
	Scope<Window> Window::create(const WindowProperties& properties) {
#ifdef _WIN32
		return CreateScope<Win32Window>(properties);
#else
		GH_ASSERT(0, "Unrecognized platform");
		return nullptr;
#endif
	}
}
