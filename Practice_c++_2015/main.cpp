/**
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
#include <iostream>
#include <exception>
#include "expression.h"
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
			std::cin.get();
		}
		catch (...) {
			std::cerr << "Exeption\n";
			std::cin.get();
		}
	}
}
int main() {

	
		calculate();
		system("pause");
	
}

