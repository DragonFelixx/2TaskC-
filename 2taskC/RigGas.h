#pragma once
#include "Rig.h"

class RigGas : public Rig
{
public:
	using Rig::Rig;

	void punp(int* oil, int* gas, int* water, int max_valume);

	~RigGas();
};

