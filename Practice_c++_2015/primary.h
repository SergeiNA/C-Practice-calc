#pragma once
#include "token_stream.h"
#include <exception>
#include "expression.h"

double expression(); 
// work witch brackets and numbers
token_stream ts;
double primary() {
	token t = ts.get();
	switch (t.kind) {
	case '(': {
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			throw std::exception(" end &brascete& ) not found\n");
		return d;
	}
	case '8':
		return t.value;
	case ';': case 'q': {
		ts.put_back(t);
		return t.value;
	}
	default:
		throw std::exception("primary expession not found\n");

	}
}
