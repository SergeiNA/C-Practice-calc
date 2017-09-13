#pragma once
#include <cmath>
#include "primary.h"
#include <exception>
#include "std_lib_facilities.h"
// work with * and /
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
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(primary());
			if (i2 == 0) error("%: divide by zero\n");
			left = i1%i2;
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