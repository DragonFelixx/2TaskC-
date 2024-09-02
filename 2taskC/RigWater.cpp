#include "RigWater.h"
#include <iostream>
using namespace std;

void RigWater::punp(int* oil, int* gas, int* water, int max_valume)
{
	int free_valume = max_valume - *oil - *gas - *water;
	if (free_valume - power < 0)
	{
		this->valume += free_valume;
		*water += free_valume;
	}
	else
	{
		this->valume += this->power;
		*water += this->power;
	}
}

RigWater::~RigWater()
{
	cout << "deleting rig water" << endl;
}
