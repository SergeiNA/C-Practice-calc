#include "token_stream.h"
#include <exception>
#include <iostream>
#include <ctype.h>

void token_stream::put_back(token t) {
	if (full) throw std::exception(" buffer is full\n");
	buffer = t;
	full = true;
}

// ignor all symbols while ';' or 'q'
void token_stream::ignore(char ch)
{
	if (full&& ch == buffer.kind) {
		full = false;
		return;
	}

	if (full&& quit == buffer.kind) return;

	full = false;

	char c = 0;
	while (std::cin >> c) {
		if (c == ch) return;
		if (ch == quit) {
			std::cin.putback(ch);
			return;
		}
	}
		
}

// Get a sumbol form cin stream and return token type of it
token token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	std::cin >> ch;
	switch (ch) {
		// for symbols, variables and functions
	case print:			// t.kind == ; (print) mean end of expression and type the result
	case quit:			// t.kind == q; (quit) close the program
	case '(': case ')': 
	case '{': case '}': 
	case 'k':
	case f_permut:		// P(a,b) permut func of permutation
	case f_combin:		// C(a,b) combin func of combination
	case '=':			// for variables
	case 'h':
		//for operations
	case ',':
	case '+': case '-': case '*': case '/': case '!': 
		return token{ ch };
		// for numbers
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': {
		std::cin.putback(ch);
		double val;
		std::cin >> val;
		return token{ number,val };
	}
	default:	 
		// for variables
		if(isalpha(ch)) {
			std::string s;
			s += ch;
			while (std::cin.get(ch) &&						// check for "let" or correct varName
				(ch=='_'|| isalpha(ch) || iswdigit(ch)))
				s += ch;
			std::cin.putback(ch);
			if (s == declkey)					
				return token(let);
			if (s == combinkey)
				return token(f_combin);
			if (s == permutkey)
				return token(f_permut);
			if (s == sqrtkey)
				return token(f_sqrt);
			if (s == powkey)
				return token(f_pow);
			if (s == quitkey)
				return token(quit);
			if (s == printkey)
				return token(print);
			return token{ v_name, s };
		}
		throw std::exception("token_stream: unknown lexem\n");

	}
}