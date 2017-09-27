#pragma once
/* Class variables
-	purpose for storage, edit and use variables
*/
#include <string>
#include <vector>
#include <exception>
class CVariables
{
public:
	std::string name;		
	double		value;
	bool		isConst;
public:
	// establish value of variable
	static double		get_value	(const std::string& );
	// define the variable as (VarName, VarValue)
	static double		define_name	(const std::string& , const double&,const bool);
	static void			set_value	(const std::string&, const double&);
						CVariables	(const std::string&, const double&, const bool);
						~CVariables	();
private:
	// set the current value for the current VarName
	
	// Check if variable with this name already exist
	static bool						is_declered(const std::string& var);
	// contains all variables
	static std::vector<CVariables>	var_table; 
};



