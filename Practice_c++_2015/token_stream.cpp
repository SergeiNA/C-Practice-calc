#include "token_stream.h"
#include <exception>
#include <iostream>

void token_stream::put_back(token t) {
	if (full) throw std::exception(" buffer is full\n");
	buffer = t;
	full = true;
}
void token_stream::ignore(char ch)
{
	if (full&& ch == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char c = 0;
	while (std::cin >> c)
		if (c == ch) return;
}
token token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	std::cin >> ch;
	switch (ch) {
	case print:			// t.kind == ; (print) mean end of expression and type the result
	case quit:			// t.kind == q; (quit) close the program
	case '(': case ')': 
	case '{': case '}': 
	case f_permut:		// P(a,b) permut func of permutation
	case f_combin:		// C(a,b) combin func of combination
	case ',':
	case '+': case '-': case '*': case '/': case '!': 
		return token{ ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': {
		std::cin.putback(ch);
		double val;
		std::cin >> val;
		return token{ number,val };
	}
	default:
		throw std::exception("unknown lexem\n");

	}
}