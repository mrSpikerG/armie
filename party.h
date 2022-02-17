#pragma once
#include "human.h"
struct Node {
	human* guy;
	Node* next;
	Node()
	{
		this->next = nullptr;
	}
};

//украл эту функцию из интернета p.s.: это должно работать как instanceof из джавы
template<typename Base, typename T>
inline bool instanceof(const T*) {
	return is_base_of<Base, T>::value;
}

class party
{
private:
	size_t size;
	Node* commander;
public:

	void addWarrior() {
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

	void addHorseMan() {
		if (commander == nullptr) {
			this->commander = new Node;
			this->commander->guy = new horseman(); //;
		}
		else {
			Node* tmp = this->commander;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node;
			tmp->next->next = nullptr;
			tmp->next->guy = new horseman();//;
		}
		this->size++;
	}

	void addBowMan() {
		if (commander == nullptr) {
			this->commander = new Node;
			this->commander->guy = new bowman(); //;
		}
		else {
			Node* tmp = this->commander;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node;
			tmp->next->next = nullptr;
			tmp->next->guy = new bowman();
		}
		this->size++;
	}

	void remove(int num) {
		if (num == 0) {
			this->commander = this->commander->next;
		}
		else {
			Node* tmp = this->commander;
			for (int i = 0; i < num-1; i++) {
				tmp = tmp->next;
			}
			tmp->next = tmp->next->next;
		}
		

		this->size--;

	}

	void info() {
		int warriors = 0;
		int bowmans = 0;
		int horsemans = 0;
		Node* tmp = this->commander;
		while (tmp->next != nullptr) {

			if (instanceof<warrior>(tmp->guy)) { warriors++; }
			if (instanceof<bowman>(tmp->guy)) { bowmans++; }
			if (instanceof<horseman>(tmp->guy)) { horsemans++; }

			tmp = tmp->next;
		}
		cout << "Warriors: " << warriors;
		cout << "Bowmans: " << bowmans;
		cout << "Horsemans: " << horsemans;
	}

	human* getById(int id) {
		if (id < this->size) {

			Node* tmp = this->commander;
			for (int i = 0; i < id; i++) {
				tmp = tmp->next;
			}
			return tmp->guy;
		}
	}

	size_t getSize() {
		return this->size;
	}
};

