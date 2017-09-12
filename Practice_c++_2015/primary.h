#pragma once
#include "token_stream.h"
#include <exception>
#include "expression.h"
#include "fractal.h"
#include "Permutation.h"
#include "Combination.h"

double expression();
token_stream ts;
unsigned int permutation(token&);
unsigned int combination(token&);

// work witch brackets and numbers

double primary() {
	token t = ts.get();
	switch (t.kind) {

	case 'P': {					// Permutation
		return permutation(t);
	}
			  
	case 'C': {					// Combination
		return combination(t);
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

	case '-':
		return -primary();
	case '+':
		return primary();

	case number: {
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
// permutation and combination func defining
unsigned int permutation(token& t) {
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
unsigned int combination(token& t) {
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