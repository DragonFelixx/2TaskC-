#include "Field.h"
#include <iostream>
using namespace std;

Field::Field(int oil, int gas, int water)
{
	this->oil = oil;
	this->gas = gas;
	this->water = water;
	this->max_valume = oil + gas + water;
}

int Field::get_oil()
{
	return this->oil;
}

int Field::get_gas()
{
	return this->gas;
}

int Field::get_water()
{
	return this->water;
}

int Field::get_max_valume()
{
	return this->max_valume;
}

vector<Rig*> Field::get_rigs()
{
	return this->rigs;
}

void Field::add_rig(Rig* rig)
{
	this->rigs.push_back(rig);
}

void Field::delete_rig(int index)
{
	delete rigs[index];
	this->rigs.erase(this->rigs.begin() + index);
}

Rig* Field::get_rig(int index)
{
	return rigs[index];
}

void Field::punp_rigs()
{
	for (auto rig : rigs)
	{
		if (rig->get_status())
		{
			rig->punp(&this->oil, &this->gas, &this->water, this->max_valume);
		}
	}
}

Field::~Field()
{
	for (auto rig : rigs)
	{
		delete rig;
	}
	cout << "deleting field" << endl;
}
