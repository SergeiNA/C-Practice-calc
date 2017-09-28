#pragma once
#include "token_stream.h"
#include <exception>
#include "expression.h"
#include "fractal.h"
#include "Permutation.h"
#include "Combination.h"
#include "Debug_func.h"
namespace parcl {
	/* Work with primary exprssion like brakets (), braces {},
	-	unar '+' and '-', permutation and combination, variables
	-	and numbers
	*/

	double expression(token_stream&);

	// work with stream of symbols

	unsigned int permutation(token_stream&);
	unsigned int combination(token_stream&);
	double		 sqrt_v(token_stream&);
	double		 pow_v(token_stream&);
	// work witch brackets and numbers

	double primary(token_stream& ts) {
		token t = ts.get();
		if (DEBUG)
			dout("[Primary]: token_kind: ", t.kind);
		switch (t.kind) {

		case f_permut: 				// Permutation
			return permutation(ts);

		case f_combin: 				// Combination
			return combination(ts);

		case sqrt:
			return sqrt_v(ts);

		case f_pow:
			return pow_v(ts);
		case help:

		case '(': {
			double d = expression(ts);
			t = ts.get();
			if (DEBUG)
				dout("[Primary]: token_kind: ", t.kind);
			if (t.kind != ')')
				throw std::exception("[Primary]: end brackets ) not found\n");
			return d;
		}

		case '{': {
			double d = expression(ts);
			t = ts.get();
			if (DEBUG)
				dout("[Primary]: token_kind: ", t.kind);
			if (t.kind != '}')
				throw std::exception("[Primary]: end brackets } not found\n");
			return d;
		}

		case '-':
			return -primary(ts);
		case '+':
			return primary(ts);
		case v_name: {
			auto temp_name = t.name;
			t = ts.get();
			if (t.kind == assign) {
				auto temp = expression(ts);
				CVariables::set_value(temp_name, temp);
				return temp;
			}

			else {
				ts.put_back(t);
				return CVariables::get_value(temp_name);
			}

		}

		case number: {						// Check if it is a
			double temp = t.value;			// number or fractal
			t = ts.get();
			if (DEBUG)
				dout("[Primary]: token_kind: ", t.kind);
			if (t.kind == '!')
				return fractal(temp);
			if (t.kind == 'k')
				return temp * 1000;
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
	unsigned int permutation(token_stream& ts) {
		auto t = ts.get();
		unsigned int a;
		unsigned int b;
		if (t.kind == '(') {		// func view have to be like P(expr,expr)
			a = expression(ts);
			t = ts.get();
			if (t.kind == ',')
				b = expression(ts);
			else {
				throw std::exception("Invalid arguments for F[Permutation]: maybe ',' is missed\n");
			}

		}
		else {
			throw std::exception("Invalid arguments for F[Permutation]: maybe '(' is missed\n");
		}
		t = ts.get();
		if (t.kind == ')')
			return Perm(a, b);
		else {
			throw std::exception("Invalid arguments for F[Permutation]: maybe ')' is missed\n");
		}
	}
	unsigned int combination(token_stream& ts) {
		auto t = ts.get();
		unsigned int a;
		unsigned int b;
		if (t.kind == '(') {		// func view have to be like C(expr,expr)
			a = expression(ts);
			t = ts.get();
			if (t.kind == ',')
				b = expression(ts);
			else {
				throw std::exception("Invalid arguments for F[Combination]: maybe ',' is missed\n");
			}

		}
		else {
			throw std::exception("Invalid arguments for F[Combination]: maybe '(' is missed\n");
		}
		t = ts.get();
		if (t.kind == ')')
			return comb(a, b);
		else {
			throw std::exception("Invalid arguments for F[Combination]: maybe ')' is missed\n");
		}
	}

	double sqrt_v(token_stream& ts) {
		auto t = ts.get();
		double a;
		if (t.kind == '(') {		// func view have to be like C(expr,expr)
			a = expression(ts);
			if (a < 0) {
				throw std::exception("Invalid arguments for F[Sqrt]: The number under the root is <0\n");
			}
		}
		else {
			throw std::exception("Invalid arguments for F[Sqrt]: maybe '(' is missed\n");
		}
		t = ts.get();
		if (t.kind == ')')
			return std::sqrt(a);
		else {
			throw std::exception("Invalid arguments for F[Sqrt]: maybe ')' is missed\n");
		}
	}


	double pow_v(token_stream& ts) {
		auto t = ts.get();
		double a;
		unsigned int b;
		if (t.kind == '(') {		// func view have to be like C(expr,expr)
			a = expression(ts);
			t = ts.get();
			if (t.kind == ',')
				b = expression(ts);
			else {
				throw std::exception("Invalid arguments for F[POW]: maybe ',' is missed\n");
			}

		}
		else {
			throw std::exception("Invalid arguments for F[POW]: maybe '(' is missed\n");
		}
		t = ts.get();
		if (t.kind == ')')
			return pow(a, b);
		else {
			throw std::exception("Invalid arguments for F[POW]: maybe ')' is missed\n");
		}
	}
}