#pragma once
class weapon {
protected:
    int damage;
    
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

class bow :public weapon {
public:
    bow()
    {
        damage = 20;
    }
};

class spear :public weapon {
public:
    spear()
    {
        damage = 15;
    }
};
class arrow :public weapon {
public:
    arrow()
    {
        damage = 20;
    }

    virtual int atack() {
        //удар стрелой в рукопашной :D
        return damage/2;
    }
};
class quiver :public arrow{
private:
    int size;
    arrow** mas;

    void decrease() {
        this->size--;
        delete mas[size];
    }
public:

    quiver() {
        this->size = 0;
        mas = new arrow*;
    }
    quiver(int size) {
        this->size = size;
        mas = new arrow*;

        for (int i = 0; i < size; i++) {
            mas[i] = new arrow;
        }
    }

    virtual int atack() {
        if (size > 0) {
            decrease();
            return damage;
        }
    }

    int getSize() {
        return this->size;
    }

};

