#pragma once
#include <string>
#include <vector>
#include <exception>
// Class variables
// purpose for storage, edit and use variables
namespace parcl {
	class CVariables
	{
	public:
		std::string name;		// variable name
		double		value;		// value of variable
		bool		isConst;	// const variable or not
	public:
		// establish value of variable
		static double		get_value(const std::string&);
		// define the variable as (VarName, VarValue)
		static double		define_name(const std::string&, const double&, const bool);
		static void			set_value(const std::string&, const double&);
		CVariables(const std::string&, const double&, const bool);
		~CVariables();
	private:
		// set the current value for the current VarName

		// Check if variable with this name already exist
		static bool						is_declered(const std::string& var);
		// contains all variables
		static std::vector<CVariables>	var_table;
	};
}