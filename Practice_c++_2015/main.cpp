/**
--------------------------------------------------------------
*	15.09.2017
*	���������� ������� calculate()
*	������ ���� � ������������� ����������
---------------------------------------------------------------
*	21.09.2017
*	������ �������� � �������� ����������, ����� primary() ��������
*	���������� � ��� ���� �������� ���� ������
*	������� ���� 1++; ������� ";" � ������� clean_up_mess()
*	��������� ���������� ����� ";"
*
*	����������� ������� ������������� ����������
*	��������� ������������
---------------------------------------------------------------
*	22.09.2017
*	��������� �����������
---------------------------------------------------------------
*	25.09.2017
*	����������� ������������� ���� � ��������������
*	������� pow (a,b) � ������� sqrt (a,b)
*	��������� ������� dout ��� �������� ���������
---------------------------------------------------------------
*	27.09.2017
*	���������� ������� "help"
*	���������� ����������� ������������ ��� ���������� '='
*	�������� ����� � ���� ��������
*	����������� ����������� ���������� ����������� ����������
---------------------------------------------------------------
*	28.09.2017
*	������ ���������� ���������� ts
*	������ ��� ���������� � �������� ���������� � ������
*	expression, primary, term � �.�.
*	����������� ��������� ������������ ���� ��� ������� �������
*	parcl
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

#define DEBUG 0
#define CONST true

#include "Variables.h"
#include <iostream>
#include <exception>
#include "expression.h"
#include "help_info.h"

// init vector of variables
// it will contain all variables
std::vector<parcl::CVariables>  parcl::CVariables::var_table;


// clean input stream after errors
// ignore all symbols while ";"
void clean_up_mess(parcl::token_stream& ts) {
	ts.ignore(parcl::print);
}


// Function for variable declaration
// save name and value of variable in var_table
// then return value of variable

double declaration(parcl::token_stream& ts) {
	bool isConst = false;
	parcl::token t = ts.get();
	if (t.kind == parcl::const_v) { // declare as const variable or not
		isConst = true;
	    t = ts.get();
	}
	if (t.kind != parcl::v_name)
		throw std::exception("variable name not defined\n");
	std::string var_name = t.name;
	parcl::token t2 = ts.get();
	if (t2.kind != '=')
		throw std::exception("The '=' is missing\n");
	double d = expression(ts);
	parcl::CVariables::define_name(var_name, d,isConst);
	return d;
}

// expression or declaration of variable
double statement(parcl::token_stream& ts) {
	parcl::token t = ts.get();
	switch (t.kind) {
	case parcl::let:
		return declaration(ts);
	default:
		ts.put_back(t);
		return expression(ts);
	}
}



// Work in cycle with input data
void calculate(parcl::token_stream& ts) {

	while (std::cin) {
		try {
			std::cout << ">> ";
			parcl::token t = ts.get();
			while (t.kind == parcl::print) t = ts.get();		// eat all ';'
			if (t.kind == parcl::quit) return;
			ts.put_back(t);
			if (t.kind == parcl::help) {
				parcl::help_info();
				std::cout << ">> ";
			}
			std::cout << "= " << statement(ts) << '\n';
		}
		catch (std::exception& e) {
			std::cerr << e.what() << '\n';
			clean_up_mess(ts);
		}
		catch (...) {
			std::cerr << "Exeption\n";
			clean_up_mess(ts);
		}
	}
}



int main() {
	// constant variables
	parcl::CVariables::define_name((std::string)"pi", 3.1415926535, CONST);
	parcl::CVariables::define_name((std::string)"e", 2.7182818284, CONST);
	parcl::token_stream ts;
	calculate(ts);

	system("pause");
}

