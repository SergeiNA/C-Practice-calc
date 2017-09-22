#pragma once
// work with * , / and %
#include <cmath>
#include "primary.h"
#include <exception>

double term() {
	double left = primary();
	token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*': {
			left *= primary();
			t = ts.get();
			break;
		}
		case '/': {
			double d = primary();
			if (d == 0)
				throw std::exception("Divid by zero\n");
			left /= d;
			t = ts.get();
			break;
		}
		case '%': {
			double d = primary();
			if (d == 0) throw std::exception("Divide by zero!\n");
			left = std::fmod(left, d);
			t = ts.get();
			break;
		}
		default: {
			ts.put_back(t);
			return left;
		}
		}
	}
}