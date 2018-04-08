#pragma once

#include "Clams.h"
#include <iostream>

class FrozenClams : public Clams
{
public:

	FrozenClams()
	{
		std::cout << "Frozen Clams... \n";
	}
};
