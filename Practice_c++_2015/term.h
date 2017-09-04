#pragma once
#include "primary.h"
#include <exception>
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
		default: {
			ts.put_back(t);
			return left;
		}
		}
	}
}