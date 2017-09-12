#pragma once
// Storage token info 
// type of symbol and number
const char number = '8';
const char quit = 'q';
const char print = ';';
const char f_combin = 'C'; // C(a,b)
const char f_permut = 'P'; // P (a,b)
struct token {
	char kind;
	double value;
};