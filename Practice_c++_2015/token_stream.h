#pragma once
#include "token.h"
// this class work with stream cin 
// it's main work get symbols from stream 
// and if it need put them back
class token_stream
{
public:
public:
	token get();
	void put_back(token);
private:
	bool full{ false };
	token buffer;
};

