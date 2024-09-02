#include "RigGas.h"
#include <iostream>
using namespace std;

void RigGas::punp(int* oil, int* gas, int* water, int max_valume)
{
	if (*oil + *gas + *water == max_valume)
	{
		if (*gas - power < 0)
		{
			this->valume += *oil;
			*gas = 0;
		}
		else
		{
			this->valume += this->power;
			*gas -= this->power;
		}
	} 
}

RigGas::~RigGas()
{
	cout << "deleting rig gas" << endl;
}
