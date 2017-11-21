#pragma once
#include <iostream>
namespace parcl {
	void dout() { std::cerr << std::endl; }

	template <typename Head, typename... Tail>
	void dout(Head H, Tail... T) {
		std::cerr << H << ' ';
		dout(T...);
	}
}