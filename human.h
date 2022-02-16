#pragma once
#include "weapons.h"
#include "horse.h"
class human
{
protected:
	int hp;
	weapon *weap;
public:
	weapon* getWeapon() {
		return this->weap;
	}
};


class warrior :public human {
private:
public:
	warrior()
	{
		this->weap = new sword();
		this->hp = 300;
	}
};
class bowman : public human {
private:
public:
	bowman()
	{
		this->weap = new bow();
		this->hp = 115;
	}
};
class horseman : public human {
private:
	horse *Konb = new horse();
public:
	horseman()
	{
		this->weap = new spear();
		this->hp = 250 + Konb->getHP();
	}

	horse *getHorse() {
		return this->Konb;
	}

};