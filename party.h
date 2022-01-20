#pragma once
#include "human.h"
struct Node {
	human* guy;
	Node* next;
};

class party
{
private:
	unsigned int size;
	Node* commander;
public:

	void add() {
		if (commander == nullptr) {
			this->commander = new Node;
			this->commander->guy = new warrior(); //;
		}
		else {
			Node* tmp = this->commander;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node;
			tmp->next->next = nullptr;
			tmp->next->guy = new warrior();//;
		}
		this->size++;
	}
};

