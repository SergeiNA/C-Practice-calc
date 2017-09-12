#pragma once
#include "token_stream.h"
#include <exception>
#include "expression.h"
#include "fractal.h"
#include "Permutation.h"
#include "Combination.h"
double expression(); 
// work witch brackets and numbers
token_stream ts;
double primary() {
	token t = ts.get();
	switch (t.kind) {
		// Permutation
	case 'P': {
		t = ts.get();
		double a;
		double b;
		if (t.kind == '(') {		// func view have to be like P(expr,expr)
			a = expression();
			t = ts.get();
			if (t.kind == ',')
				b = expression();
			else {
				ts.put_back(t);
				throw std::exception("Invalid arguments for F[Permutation], maybe ',' is missed\n");
			}
				
		}
		else {
			ts.put_back(t);
			throw std::exception("Invalid arguments for F[Permutation], maybe '(' is missed\n");
		}
		t = ts.get();
		if (t.kind == ')') 
			return Perm(a, b);
		else {
			ts.put_back(t);
			throw std::exception("Invalid arguments for F[Permutation], maybe ')' is missed\n");
		}
	}
	case 'C': {
		t = ts.get();
		double a;
		double b;
		if (t.kind == '(') {		// func view have to be like C(expr,expr)
			a = expression();
			t = ts.get();
			if (t.kind == ',')
				b = expression();
			else {
				ts.put_back(t);
				throw std::exception("Invalid arguments for F[Combination], maybe ',' is missed\n");
			}

		}
		else {
			ts.put_back(t);
			throw std::exception("Invalid arguments for F[Combination], maybe '(' is missed\n");
		}
		t = ts.get();
		if (t.kind == ')')
			return comb(a, b);
		else {
			ts.put_back(t);
			throw std::exception("Invalid arguments for F[Combination], maybe ')' is missed\n");
		}
	}
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
