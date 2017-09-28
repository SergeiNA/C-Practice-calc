#include "Variables.h"
namespace parcl {
	double CVariables::get_value(const std::string& s) {
		for (const CVariables& v : var_table)
			if (v.name == s)return v.value;
		//std::string err = (std::string)"get : undefined variable"+ (std::string)s;
		throw std::exception("[CVariables::get_value]: undefined variable\n");
	}

	void CVariables::set_value(const std::string& s, const double& d)
	{
		for (CVariables & v : var_table)
			if (v.name == s) {
				if (v.isConst) // check if it is a const variable
					throw std::exception("[CVariables::set_value]: const variable cannot be modified\n");
				v.value = d;
				return;
			}
		throw std::exception("[CVariables::set_value]: undefined variable\n");
	}

	bool CVariables::is_declered(const std::string & var)
	{
		for (const CVariables& v : var_table)
			if (v.name == var) return true;
		return false;
	}

	double CVariables::define_name(const std::string & var, const double & val, const bool _const)
	{
		if (is_declered(var))
			throw std::exception("[CVariables::define_name]: re-declaration of variable\n");
		var_table.push_back(CVariables(var, val, _const));
		return val;
	}

	CVariables::CVariables(const std::string &var, const double &val, const bool _const) :
		name(var), value(val), isConst(_const)
	{
	}


	CVariables::~CVariables()
	{
	}
}