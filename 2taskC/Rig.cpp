#include "Rig.h"
#include <iostream>
#include <string>
using namespace std;

Rig::Rig(int power, string name)
{
	this->power = power;
	this->name = name;
	this->status = false;
	this->valume = 0;
}

void Rig::change_power(int power)
{
	this->power = power;
}

Rig::~Rig()
{
	cout << "deleting rig" << endl;
}

int Rig::get_status()
{
	return this->status;
}

int Rig::get_valume()
{
	return this->valume;
}

int Rig::get_power()
{
	return this->power;
}

string Rig::get_name()
{
	return this->name;
}

void Rig::punp(int* oil, int* gas, int* water, int max_valume)
{
}

void Rig::change_status()
{
	if (this->status)
	{
		this->status = false;
	}
	else 
	{
		this->status = true;
	}
}
