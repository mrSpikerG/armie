#include <iostream>
#include "party.h"

//template<typename Base, typename T>
//inline bool instanceof(const T*) {
//	return is_base_of<Base, T>::value;
//}

void war(party* first, party *second) {
	
	/*if (first->getSize() < second->getSize()) {
		swap(first, second);
	}*/


	int i = 0, j = 0;

	while (true) {
		if (i == first->getSize()) { i = 0; }
		if (j == second->getSize()) { j = 0; }

		second->getById(j)->setHP(first->getById(i)->getWeapon()->atack() + second->getById(j)->getHP());
		/*if (instanceof<warrior>(first->getById(i))) { cout << "\nВоин ударил "; };
		if (instanceof<horseman>(first->getById(i))) { cout << "\nНаездник ударил "; };
		if (instanceof<bowman>(first->getById(i))) { cout << "\nЛучник выстрелил в "; };

		if (instanceof<warrior>(second->getById(j))) { cout << "Воина"; };
		if (instanceof<horseman>(second->getById(j))) { cout << "Наездника"; };
		if (instanceof<bowman>(second->getById(j))) { cout << "Лучника"; };*/

		if (second->getById(j)->getHP() <= 0) {
			second->remove(j);
			/*if (instanceof<warrior>(second->getById(j))) { cout << "\nВоин умер"; };
			if (instanceof<horseman>(second->getById(j))) { cout << "\nНаездник умер"; };
			if (instanceof<bowman>(second->getById(j))) { cout << "\nЛучник умер"; };*/

		}
		
		first->getById(i)->setHP(second->getById(j)->getWeapon()->atack() + first->getById(i)->getHP());
		/*if (instanceof<warrior>(second->getById(j))) { cout << "\nВоин ударил "; };
		if (instanceof<horseman>(second->getById(j))) { cout << "\nНаездник ударил "; };
		if (instanceof<bowman>(second->getById(j))) { cout << "\nЛучник выстрелил в "; };

		if (instanceof<warrior>(first->getById(i))) { cout << "Воина"; };
		if (instanceof<horseman>(first->getById(i))) { cout << "Наездника"; };
		if (instanceof<bowman>(first->getById(i))) { cout << "Лучника"; };*/

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
