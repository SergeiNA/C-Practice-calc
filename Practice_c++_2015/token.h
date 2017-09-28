#pragma once
// Storage token info 
// token can contain symbol (operator), value (namber) and variable (name and value)
#include <string>
namespace parcl {
	// predefined constants 
	const char number = '8';		// define type 'number'
	const char quit = 'q';		// define command quit
	const char print = ';';		// define command print
	const char f_combin = 'C';		// define combination function C(a,b)
	const char f_permut = 'P';		// define permutation function P(a,b)
	const char let = 'L';		// define variable in program
	const char sqrt = 'S';		// define sqrt function sqrt(a,b)
	const char f_pow = 'W';		// define power function pow(a,b)
	const char v_name = 'a';		// define type 'variable name'
	const char const_v = 'c';
	const char assign = '=';
	const char help = 'h';
	const std::string constkey = "const";
	const std::string declkey = "let";	// declaration key in stream to define variable
	const std::string quitkey = "exit";	// declaration key in stream to quit or 'q'
	const std::string printkey = "print";	// declaration key in stream to print or ';'
	const std::string permutkey = "perm";	// declaration key in stream to define combination function C(a,b)
	const std::string combinkey = "comb";	// declaration key in stream to define permutation function P(a,b)
	const std::string sqrtkey = "sqrt";	// declaration key in stream to define sqrt function sqrt(a,b)
	const std::string powkey = "pow";	// declaration key in stream to define power function pow(a,b)
	const std::string helpkey = "help";


	struct token {
		char kind;
		double value;
		std::string name; // for storage variable

		token() :kind{ '-' }, value{ 0 }, name{ "none" } {}
		// initializate operator
		token(char ch) :kind{ ch } {}
		// initializate number
		token(char ch, double val) : kind{ ch }, value{ val } {}
		// initializate variable
		token(char ch, std::string _name) : kind{ ch }, name(_name) {}
		token(std::string _name) : name(_name) {}
	};
}