#pragma once
#include <string>
using namespace std;

class Rig
{
protected:
	bool status;
	int valume;
	int power;
	string name;

public:
	Rig(int power, string name);

	void change_power(int power);

	int get_status();
	int get_valume();
	int get_power();
	string get_name();

	void change_status();

	~Rig();

	virtual void punp(int* oil, int* gas, int* water, int max_valume);
};

