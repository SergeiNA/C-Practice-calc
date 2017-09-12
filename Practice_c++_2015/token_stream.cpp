#include "token_stream.h"
#include <exception>
#include <iostream>

void token_stream::put_back(token t) {
	if (full) throw std::exception(" buffer is full\n");
	buffer = t;
	full = true;
}
token token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	std::cin >> ch;
	switch (ch) {
	case ';':
	case 'q':
	case '(': case ')': case '{': case '}':
	case '+': case '-': case '*': case '/': case '!':
		return token{ ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': {
		std::cin.putback(ch);
		double val;
		std::cin >> val;
		return token{ '8',val };
	}
	default:
		throw std::exception("unknown lexem\n");

	}
}