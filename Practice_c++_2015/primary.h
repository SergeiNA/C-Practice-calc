#pragma once
#include "token_stream.h"
#include <exception>
#include "expression.h"
#include "fractal.h"
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
			throw std::exception("end brackets ) not found\n");
		return d;
	}
	case '{': {
		double d = expression();
		t = ts.get();
		if (t.kind != '}')
			throw std::exception("end brackets } not found\n");
		return d;
	}
	case '8': {
		double temp=t.value;
		t = ts.get();
		if (t.kind == '!') {
			return fractal(temp);
		}
		else {
			ts.put_back(t);
			return temp;
		}
		
	}
	case ';': case 'q': {
		ts.put_back(t);
		return t.value;
	}
	default:
		throw std::exception("primary expession not found\n");

	}
}
