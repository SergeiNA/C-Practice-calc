#pragma once
// Storage token info 
// type of symbol and number
#include <string>
const char number			= '8';
const char quit				= 'q';
const char print			= ';';
const char f_combin			= 'C';		// C(a,b)
const char f_permut			= 'P';		// P (a,b)
const char let				= 'L';
const std::string declkey	= "let";
const char v_name			= 'a';		// variable name

struct token {
	char kind;
	double value;
	std::string name; // for storage variable

	token ():kind{'-'},value{0},name{"none"} {}
	// initializate operator
	token(char ch) :kind{ ch } {}
	// initializate number
	token(char ch, double val) : kind{ ch }, value{ val } {}
	// initializate variable
	token(char ch, std::string _name) : kind{ ch }, name(_name) {}
};