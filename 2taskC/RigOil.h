#pragma once
#include "Rig.h"

class RigOil : public Rig
{
public:
	using Rig::Rig;

	void punp(int* oil, int* gas, int* water, int max_valume);

	~RigOil();
};

