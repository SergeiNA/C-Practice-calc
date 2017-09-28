#pragma once

#include <cmath>
#include "primary.h"
#include <exception>
// work with * , / and %
namespace parcl {
	double term(token_stream& ts) {
		double left = primary(ts);
		token t = ts.get();
		while (true) {
			switch (t.kind) {
			case '*': {
				left *= primary(ts);
				t = ts.get();
				break;
			}
			case '/': {
				double d = primary(ts);
				if (d == 0)
					throw std::exception("Divid by zero\n");
				left /= d;
				t = ts.get();
				break;
			}
			case '%': {
				double d = primary(ts);
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
}