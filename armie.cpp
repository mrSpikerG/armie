#include <iostream>
#include "party.h"



void war(party* first, party *second) {
	
	int i = 0, j = 0;

	while (first->getSize() > 0||second->getSize()>0) {
		if (i >= first->getSize()) { i = 0; }
		if (j >= second->getSize()) { j = 0; }

		second->getById(j)->setHP(second->getById(j)->getHP() - first->getById(i)->getWeapon()->atack());
		cout <<"\n" << first->getById(i)->getType() << " атаковал " << second->getById(j)->getType() << "a";

		if (second->getById(j)->getHP() <= 0) {
			cout << "\n" << second->getById(j)->getType() << " умер";
			second->remove(j);
		}
		
		if (first->getSize() == 0) {
			cout << "\nВторая армия победила";
			break;
		}
		

		first->getById(i)->setHP(first->getById(i)->getHP() -second->getById(j)->getWeapon()->atack() );
		cout << "\n" << first->getById(i)->getType() << " атаковал " << second->getById(j)->getType() << "a";


		if (first->getById(i)->getHP() <= 0) {
			cout <<"\n"<< first->getById(i)->getType() << " умер";
			first->remove(i);
		}

		j++;
		i++;

	
		if (second->getSize() == 0) {
			cout << "\nПервая армия победила";
			break;
		}

	}
		for (int j = 0; j < second->getSize(); j++) {
		}
}
int main()
{
	setlocale(LC_ALL,"");
	party* Estonia = new party();
	party* Rome = new party();

	Estonia->addWarrior();
	Estonia->addWarrior();
	Estonia->addWarrior();
	Estonia->addWarrior();
	Estonia->addHorseMan();
	Estonia->addHorseMan();
	Estonia->addBowMan();

	Rome->addWarrior();
	Rome->addWarrior();
	Rome->addWarrior();
	Rome->addHorseMan();
	Rome->addBowMan();
	Rome->addBowMan();
	Rome->addBowMan();
	Rome->addBowMan();
	Rome->addHorseMan();
	Rome->addBowMan();
	Rome->addBowMan();

	//Rome->info();
	war(Rome,Estonia);
	//cout<<Estonia->getById(1)->getWeapon()->atack();


}
