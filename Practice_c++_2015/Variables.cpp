#include "Variables.h"



double CVariables::get_value(const std::string& s) {
	for (const CVariables& v : var_table)
		if (v.name == s)return v.value;
	//std::string err = (std::string)"get : undefined variable"+ (std::string)s;
	throw std::exception("get : undefined variable\n");
}

void CVariables::set_value(const std::string s , const double d)
{
	for (CVariables & v: var_table)
		if (v.name == s) {
			v.value = d;
			return;
		}
	throw std::exception("set: undefined variable\n");
}

bool CVariables::is_declered(const std::string & var) 
{
	for (const CVariables& v : var_table)
		if (v.name == var) return true;
	return false;
}

double CVariables::define_name(const std::string & var, const double & val)
{
	if (is_declered(var)) throw std::exception("re-declaration of variable\n");
	var_table.push_back(CVariables(var, val));
	return val;
}

CVariables::CVariables(const std::string &var, const double &val): name(var), value(val)
{
}


CVariables::~CVariables()
{
}
