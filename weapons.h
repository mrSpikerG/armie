#include <iostream>
using namespace std;

#pragma once
class weapon {
protected:
    int damage;
    
public:
    virtual int atack() {
        return damage;
    }
};

class sword :public weapon {
public:
    sword()
    {
        damage = 10;
    }
};



class spear :public weapon {
public:
    spear()
    {
        damage = 15;
    }
};
//class arrow :public weapon {
////
//// если не забуду, то здесь должен появится коэфициентов урона
////
//};
class quiver{
private:
    int size;
public:

    
   

    void decrease() {
        this->size--;
    }

    quiver() {
        this->size = 21;
    }

    int getSize() {
        return this->size;
    }
};


//                                                  //
//  здесь могла быть нормальная реализация колчана  //
//                                                  //
class bow :public weapon {

protected:
    quiver* kolchan = new quiver();
public:
    bow()
    {
        this->damage = 20;
    }
    int atack() {
        if (kolchan->getSize() > 0) {
            kolchan->decrease();
            return damage;
        }
        //дерется луком без стрел
            return 1;
    }
};