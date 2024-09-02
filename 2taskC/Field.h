#pragma once
#include "Rig.h"
#include <vector>
using namespace std;

class Field
{
private:
	int oil;
	int gas;
	int water;
	int max_valume;
	vector<Rig*> rigs;

public:
	Field(int oil, int gas, int water);

	int get_oil();
	int get_gas();
	int get_water();
	int get_max_valume();
	vector<Rig*> get_rigs();

	void add_rig(Rig* rig);

	void delete_rig(int index);

	Rig* get_rig(int index);

	void punp_rigs();

	~Field();
};

