#include "RigOil.h"
#include <iostream>
using namespace std;

void RigOil::punp(int* oil, int* gas, int* water, int max_valume)
{
	if (*oil + *gas + *water == max_valume)
	{
		if (*oil - power < 0)
		{
			this->valume += *oil;
			*oil = 0;
		}
		else
		{
			this->valume += this->power;
			*oil -= this->power;
		}
	}
}

RigOil::~RigOil()
{
	cout << "deleting rig oil" << endl;
}
