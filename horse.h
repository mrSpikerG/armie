#pragma once
class horse
{
private:
	int hp;
public:
	horse()
	{
		//сильный конь
		this->hp = 25;
	}
	int getHP() {
		return this->hp;
	}
};

