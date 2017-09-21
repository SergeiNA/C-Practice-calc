/**
--------------------------------------------------------------
*	15.09.2017
*	���������� ������� calculate()
*	������ ���� � ������������� ����������
---------------------------------------------------------------
*	21.09.2017
*	������ �������� � �������� ����������, ����� primary() ������
*	���������� � ��� ���� �������� ���� ������
*	������� ���� 1++; ������� ";" � ������� clean_up_mess()
*	��������� ���������� ����� ";"
---------------------------------------------------------------
*   Calculator with simle expression prase 
*	from Printsipy_I_Practica_S_ispolzovaniem_C_-_2015
*	Chapter 6
*	������� �����������
*	��� ��������� ��������� �������� ��������� ������������
*	���������� ��� �����:
*	
*	����������:
*		���������
*		�����
*		�����
*	�����:
*		;
*	�����:
*		q
*	���������:
*		����
*		��������� + ����
*		��������� - ����
*	����:
*		��������� ���������
*		���� * ��������� ���������
*		���� / ��������� ���������
*		���� % ��������� ���������
*	��������� ���������:
*		�����
*		( ��������� )
*		- ��������� ���������
*		+ ��������� ���������
*		��������� (�����!)
*		���������� (C(���������,���������))
*		������������ (�(���������,���������))
*	�����:
*		������� � ��������� ������
**/
#include "Variables.h"
#include <iostream>
#include <exception>
#include "expression.h"

void clean_up_mess() {
	ts.ignore(print);
}

double declaration() {
	//token t = ts.get();
	//if (t.kind != name)
	//	throw std::exception("variable name not defined\n");
	//std::string var_name = t.name;
	//token t2 = ts.get();
	//if (t2.kind != '=')
	//	throw std::exception("The '=' is missing\n");
	//double d = expression();
	//define_name(var_name, d);
	//return d;
	return 1;
}

double statement(){
	token t = ts.get();
	switch (t.kind){
	case let:
		return declaration();
	default:
		ts.put_back(t);
		return expression();
	}
}





void help() {
	std::cout << "--Permutation: tap 'P(expression,expression)'\n";
	std::cout << "--Combination: tap 'C(expression,expression)'\n";
}

void calculate() {

	while (std::cin) {
		try {
			std::cout << ">> ";
			token t = ts.get();
			while (t.kind == print) t = ts.get();		// eat all ';'
			if (t.kind == quit) return;
			ts.put_back(t);
			std::cout << "= " << statement() << '\n';
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

	help();
	calculate();
	system("pause");

}

