#pragma once
#include "term.h"
namespace parcl {
	//work with '+',  '-' and numbers
	double expression(token_stream& ts) {
		double left = term(ts);
		token t = ts.get();
		while (true) {
			switch (t.kind) {
			case '+': {
				left += term(ts);
				t = ts.get();
				break;
			}
			case '-': {
				left -= term(ts);
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