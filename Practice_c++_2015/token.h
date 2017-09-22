#pragma once
// Storage token info 
// token can contain symbol (operator), value (namber) and variable (name and value)
#include <string>
// predefined constants 
const char number			= '8';		// define type 'number'
const char quit				= 'q';		// define command quit
const char print			= ';';		// define command print
const char f_combin			= 'C';		// define function C(a,b)
const char f_permut			= 'P';		// define function P(a,b)
const char let				= 'L';		// define variable in program
const std::string declkey	= "let";	// declaration key in stream to define variable
const char v_name			= 'a';		// define type 'variable name'

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