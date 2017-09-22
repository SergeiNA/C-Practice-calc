#pragma once
#include "token.h"
// this class work with stream cin 
// it's main work get symbols from stream 
// and if it need put them back or 
// ignor all symbols while the set symbol
class token_stream
{
public:
	token get();
	void put_back(token);
	void ignore(char ch);
private:
	bool full{ false };
	token buffer;
};

