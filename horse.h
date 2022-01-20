#pragma once
class horse
{
private:
	int hp;
public:
	horse()
	{
		//сильный конь
		this->hp = 225;
	}
	int getHP() {
		return this->hp;
	}
};

