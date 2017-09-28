#pragma once
// ver 0.1 of help. Will be finalized
#include <iostream>
namespace parcl {
	void help_info() {
		std::cout << "General info: \nThis is the simple calculator with parser\n" <<
			"It supports all basic operators like '+', '-', '*', '/'\n" <<
			"Also it supports some special fuctions like pow(a,b), sqrt(a,b),\n" <<
			"permutain perm(a,b) and combination comb(a,b) functions\n" <<
			"This calculator support variables.\n" <<
			"If you want to declare variable you have to write word 'let' and\n" <<
			"name of variable\n" <<
			"For more info type\n-help calc\n-help func\n-help var\n";
	}
}