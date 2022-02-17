#include <iostream>
#include "party.h"



void war(party* first, party *second) {
	
	int i = 0, j = 0;

	while (first->getSize() > 0||second->getSize()>0) {
		if (i == first->getSize()) { i = 0; }
		if (j == second->getSize()) { j = 0; }

		second->getById(j)->setHP(second->getById(j)->getHP() - first->getById(i)->getWeapon()->atack());
		cout <<"\n" << first->getById(i)->getType() << " атаковал " << second->getById(j)->getType() << "a";

		if (second->getById(j)->getHP() <= 0) {
			second->remove(j);
			/*if (instanceof<warrior>(second->getById(j))) { cout << "\nВоин умер"; };
			if (instanceof<horseman>(second->getById(j))) { cout << "\nНаездник умер"; };
			if (instanceof<bowman>(second->getById(j))) { cout << "\nЛучник умер"; };*/

		}
		
		first->getById(i)->setHP(second->getById(j)->getWeapon()->atack() - first->getById(i)->getHP());
		cout << "\n" << first->getById(i)->getType() << " атаковал " << second->getById(j)->getType() << "a";


		if (first->getById(i)->getHP() <= 0) {
			first->remove(i);
		/*	if (instanceof<warrior>(first->getById(i))) { cout << "\nВоин умер"; };
			if (instanceof<horseman>(first->getById(i))) { cout << "\nНаездник умер"; };
			if (instanceof<bowman>(first->getById(i))) { cout << "\nЛучник умер"; };*/
		}

		j++;
		i++;

		if (first->getSize() == 0) {
			cout << "\nВторая армия победила";
			break;
		}
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
	party* Estonia = new party();
	party* Rome = new party();

	Estonia->addWarrior();
	Estonia->addWarrior();
	Estonia->addWarrior();
	Estonia->addBowMan();

	Rome->addWarrior();
	Rome->addWarrior();
	Rome->addWarrior();
	Rome->addHorseMan();
	Rome->addBowMan();
	Rome->addBowMan();
	Rome->addBowMan();
	Rome->addBowMan();

	//Rome->info();
	war(Estonia, Rome);
	//cout<<Estonia->getById(1)->getWeapon()->atack();


}
