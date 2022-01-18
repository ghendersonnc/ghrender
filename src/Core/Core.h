#pragma once

#include <memory>

#define BIND_EVENT(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace GH {
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... A>
	constexpr Scope<T> CreateScope(A&& ... args)
	{
		return std::make_unique<T>(std::forward<A>(args)...);
	}
}
