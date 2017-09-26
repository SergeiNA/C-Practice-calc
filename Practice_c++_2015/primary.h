#pragma once
/* Work with primary exprssion like brakets (), braces {},
-	unar '+' and '-', permutation and combination, variables
-	and numbers
*/
#include "token_stream.h"
#include <exception>
#include "expression.h"
#include "fractal.h"
#include "Permutation.h"
#include "Combination.h"
#include "Debug_func.h"
double expression();

// work with stream of symbols
token_stream ts;
unsigned int permutation(token&);
unsigned int combination(token&);
double		 sqrt_v		(token&);
double		 pow_v		(token&);
// work witch brackets and numbers

double primary() {
	token t = ts.get();
	if (DEBUG)
		dout("[Primary]: token_kind: ", t.kind);
	switch (t.kind) {

	case f_permut: 				// Permutation
		return permutation(t);
	  
	case f_combin: 				// Combination
		return combination(t);

	case f_sqrt : 
		return sqrt_v(t);

	case f_pow:
		return pow_v(t);
	case '(': {
		double d = expression();
		t = ts.get();
		if (DEBUG)
			dout("[Primary]: token_kind: ", t.kind);
		if (t.kind != ')')
			throw std::exception("[Primary]: end brackets ) not found\n");
		return d;
	}

	case '{': {
		double d = expression();
		t = ts.get();
		if (DEBUG)
			dout("[Primary]: token_kind: ", t.kind);
		if (t.kind != '}')
			throw std::exception("[Primary]: end brackets } not found\n");
		return d;
	}

	case '-':
		return -primary();
	case '+':
		return primary();
	case v_name: {
		auto temp_name = t.name;
		t = ts.get();
		if (t.kind == assign) {
			auto temp = expression();
			CVariables::set_value(temp_name, temp);
			return temp;
		}
			
		else {
			ts.put_back(t);
			return CVariables::get_value(temp_name);
		}
		
	}
		
	case number: {						// Check if it is a
		double temp=t.value;			// number or fractal
		t = ts.get();
		if (DEBUG)
			dout("[Primary]: token_kind: ", t.kind);
		if (t.kind == '!') 
			return fractal(temp);
		if (t.kind == 'k') 
			return temp*1000;
		else {
			ts.put_back(t);
			return temp;
		}
		
	}
	default: {
		ts.put_back(t);
		throw std::exception("[Primary]: primary expession not found\n");
	}
		

	}
}
// permutation and combination body func defining
unsigned int permutation(token& t) {
	t = ts.get();
	unsigned int a;
	unsigned int b;
	if (t.kind == '(') {		// func view have to be like P(expr,expr)
		a = expression();
		t = ts.get();
		if (t.kind == ',')
			b = expression();
		else {
			ts.put_back(t);
			throw std::exception("Invalid arguments for F[Permutation]: maybe ',' is missed\n");
		}

	}
	else {
		ts.put_back(t);
		throw std::exception("Invalid arguments for F[Permutation]: maybe '(' is missed\n");
	}
	t = ts.get();
	if (t.kind == ')')
		return Perm(a, b);
	else {
		ts.put_back(t);
		throw std::exception("Invalid arguments for F[Permutation]: maybe ')' is missed\n");
	}
}
unsigned int combination(token& t) {
	t = ts.get();
	unsigned int a;
	unsigned int b;
	if (t.kind == '(') {		// func view have to be like C(expr,expr)
		a=expression() ;
		t = ts.get();
		if (t.kind == ',')
			b = expression();
		else {
			ts.put_back(t);
			throw std::exception("Invalid arguments for F[Combination]: maybe ',' is missed\n");
		}

	}
	else {
		ts.put_back(t);
		throw std::exception("Invalid arguments for F[Combination]: maybe '(' is missed\n");
	}
	t = ts.get();
	if (t.kind == ')')
		return comb(a, b);
	else {
		ts.put_back(t);
		throw std::exception("Invalid arguments for F[Combination]: maybe ')' is missed\n");
	}
}

double sqrt_v(token& t) {
	t = ts.get();
	double a;
	if (t.kind == '(') {		// func view have to be like C(expr,expr)
		a = expression();
		if (a < 0) {
			ts.put_back(t);
			throw std::exception("Invalid arguments for F[Sqrt]: The number under the root is <0\n");
		}
	}
	else {
		ts.put_back(t);
		throw std::exception("Invalid arguments for F[Sqrt]: maybe '(' is missed\n");
	}
	t = ts.get();
	if (t.kind == ')')
		return sqrt(a);
	else {
		ts.put_back(t);
		throw std::exception("Invalid arguments for F[Sqrt]: maybe ')' is missed\n");
	}
}


double pow_v(token& t) {
	t = ts.get();
	double a;
	unsigned int b;
	if (t.kind == '(') {		// func view have to be like C(expr,expr)
		a = expression();
		t = ts.get();
		if (t.kind == ',')
			b = expression();
		else {
			ts.put_back(t);
			throw std::exception("Invalid arguments for F[POW]: maybe ',' is missed\n");
		}

	}
	else {
		ts.put_back(t);
		throw std::exception("Invalid arguments for F[POW]: maybe '(' is missed\n");
	}
	t = ts.get();
	if (t.kind == ')')
		return pow(a, b);
	else {
		ts.put_back(t);
		throw std::exception("Invalid arguments for F[POW]: maybe ')' is missed\n");
	}
}