#pragma once
#include "term.h"
//work with '+',  '-' and numbers
double expression() {
	double left = term();
	token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+': {
			left += term();
			t = ts.get();
			break;
		}
		case '-': {
			left -= term();
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