/**
*   Calculator with simle expression prase 
*	from Printsipy_I_Practica_S_ispolzovaniem_C_-_2015
*	Chapter 6
*	Простой калькулятор
*	Эта программа реализует основные выражения калькулятора
*	Грамматика для ввода:
*	
*	Инструкция:
*		Выражение
*		Вывод
*		Выход
*	Вывод:
*		;
*	Выход:
*		q
*	Выражение:
*		Терм
*		Выражение + терм
*		Выражение - Терм
*	Терм:
*		Первичное выражение
*		Терм * Первичное выражение
*		Терм / Первичное выражение
*		Терм % Первичное выражение
*	Первичное выражение:
*		Число
*		( Выражение )
*		- Первичное выражение
*		+ Первичное выражение
*		Факториал (Число!)
*		Комбинации (C(выражение,выражение))
*		Перестановки (Р(выражение,выражение))
*	Число:
*		Литерал с плавающей точкой
**/
#include <iostream>
#include <exception>
#include "expression.h"

void clean_up_mess() {
	ts.ignore(print);
}

void calculate() {
	double val = 0;
	std::cout << ">> ";
	while (std::cin) {
		try {
		token t = ts.get();
		if (t.kind == quit) break;
		if (t.kind == print)
			std::cout << "= " << val << std::endl;
		else
			ts.put_back(t);
		val = expression();
		}
		catch (std::exception& e) {
			std::cerr << e.what() << '\n';
			clean_up_mess();
		}
		catch (...) {
			std::cerr << "Exeption\n";
			clean_up_mess();
		}
	}
}
int main() {

	
		calculate();
		system("pause");
	
}

