#pragma once

#include "Clams.h"
#include <iostream>

class FreshClams : public Clams
{
public:
	FreshClams()
	{
		std::cout << "Fresh Clams... \n";
	}
};
