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
    quiver arrows;
public:
    bow()
    {
        damage = 20;
    }
    int atack() {
        if (arrows.getSize() > 0) {
            arrows.decrease();
            return damage;
        }
        //дерется луком без стрел
        return 1;
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
};
class quiver :public arrow{
private:
    int size;
    arrow** mas;

public:

    void decrease() {
        this->size--;
        delete mas[size];
    }

    quiver() {
        this->size = 20;
        mas = new arrow*;

        for (int i = 0; i < size; i++) {
            mas[i] = new arrow;
        }
    }

    int getSize() {
        return this->size;
    }
};


//                                                  //
//  здесь могла быть нормальная реализация колчана  //
//                                                  //

//struct Node :public arrow {
//    arrow* arrow;
//    Node* next;
//    Node()
//    {
//        next = nullptr;
//    }
//};
//
//template <typename T>
//class quiver {
//private:
//    Node<T>* head;
//    unsigned long long size;
//public:
//
//    List()
//    {
//        this->head = nullptr;
//        size = 0;
//    }
//
//    void add(int num) {
//
//        if (head == nullptr) {
//            this->head = new Node<T>;
//            this->head->value = num;
//        }
//        else {
//            Node<T>* tmp = this->head;
//            while (tmp->next != nullptr) {
//                tmp = tmp->next;
//            }
//            tmp->next = new Node<T>;
//            tmp->next->next = nullptr;
//            tmp->next->value = num;
//        }
//        this->size++;
//    }
//
//    void remove() {
//        if (this->head != nullptr) {
//            Node<T>* tmp = this->head;
//            this->head = this->head->next;
//            this->size--;
//        }
//    }
//
//};