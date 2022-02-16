#include <iostream>
#include "party.h"


void war(party* first, party *second) {
	
	if (first->getSize() < second->getSize()) {
		swap(first, second);
	}

	//			//
	//			//
	//			//
	//			//
	//


	for (int i = 0; i < first->getSize(); i++) {
		for (int j = 0; j < second->getSize(); j++) {


		}
	}
}
int main()
{
	party* Estonia = new party();
	party* Rome = new party();

	Estonia->addWarrior();
	Estonia->addBowMan();

	cout<<Estonia->getById(1)->getWeapon()->atack();


}
