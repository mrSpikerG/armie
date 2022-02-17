#pragma once
#include "weapons.h"
#include "horse.h"
class human
{
protected:
	int hp;
	string type;
	weapon *weap;
public:
	weapon* getWeapon() {
		return this->weap;
	}
	void setHP(int hp) {
		this->hp = hp;
	}
	int getHP() {
		return this->hp;
	}
	string getType() {
		return this->type;
	}

};


class warrior :public human {
private:
public:
	warrior()
	{
		this->weap = new sword();
		this->hp = 300;
		this->type = "Воин";
	}
};
class bowman : public human {
private:
public:
	bowman()
	{
		this->weap = new bow();
		this->hp = 115;
		this->type = "Лучник";
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
		this->type = "Наездник";
	}

	horse *getHorse() {
		return this->Konb;
	}

};