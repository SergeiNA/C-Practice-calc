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
	double		get_value(const std::string& );
	void		set_value(std::string , double );
	bool		is_declered(std::string& var);
	double		define_name(std::string& , double&);
				CVariables(const std::string&, const double&);
				~CVariables();
private:
	std::vector<CVariables> var_table; // ?? static
};



