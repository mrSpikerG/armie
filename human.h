#pragma once
#include "weapons.h"
#include "horse.h"
class human
{
protected:
	int hp;
	weapon *weapon;
public:
};


class warrior :public human {
private:
public:
	warrior()
	{
		this->weapon = new sword();
		this->hp = 300;
	}
};
class bowman : public human {
private:
	bowman()
	{
		this->weapon = new bow();
		this->hp = 115;
	}
public:
};
class horseman : public human {
private:
	horse *Konb = new horse();
public:
	horseman()
	{
		this->weapon = new spear();
		this->hp = 250;
	}
};