#pragma once
#include <string>
#include <vector>
#include <exception>
class CVariables
{
public:
	std::string name;
	double		value;
public:
	static double		get_value(const std::string& );
	static void			set_value(std::string , double );
	static bool			is_declered(std::string& var);
	static double		define_name(std::string& , double&);
						CVariables(const std::string&, const double&);
						~CVariables();
private:
	static std::vector<CVariables> var_table; // ?? static
};



