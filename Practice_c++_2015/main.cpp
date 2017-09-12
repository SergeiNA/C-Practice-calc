/**
*   Calculator with simle expression prase 
*	from Printsipy_I_Practica_S_ispolzovaniem_C_-_2015
*	Chapter 6
*	update
**/
#include <iostream>
#include <exception>
#include "expression.h"
int main() {

	try {
		double val = 0;
		while (std::cin) {
			//std::cout << ">> ";
			token t = ts.get();
			if (t.kind == 'q') break;
			if (t.kind == ';')
				std::cout <<"= "<< val << std::endl;
			else
				ts.put_back(t);
			val = expression();
		}
		system("pause");
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		system("pause");
		return 1;
	}
	catch (...) {
		std::cerr << "Exeption\n";
		system("pause");
		return 2;
	}
}

