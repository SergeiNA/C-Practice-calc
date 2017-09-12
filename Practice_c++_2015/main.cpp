/**
*   Calculator with simle expression prase 
*	from Printsipy_I_Practica_S_ispolzovaniem_C_-_2015
*	Chapter 6
*	update
**/
#include <iostream>
#include <exception>
#include "expression.h"
void calculate() {
	double val = 0;
	std::cout << ">> ";
	while (std::cin) {
		token t = ts.get();
		if (t.kind == quit) break;
		if (t.kind == print)
			std::cout << "= " << val << std::endl;
		else
			ts.put_back(t);
		val = expression();
	}
}
int main() {

	try {
		calculate();
		system("pause");
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		std::cout << "If you want close window press `\n";
		char ch;
		for (char ch; std::cin >> ch;)
			if (ch == '`') return 1;
		//system("pause");
		return 1;
	}
	catch (...) {
		std::cerr << "Exeption\n";
		std::cout << "If you want close window press `\n";
		char ch;
		for (char ch; std::cin >> ch;)
			if (ch == '`') return 1;
		//system("pause");
		return 2;
	}
}

