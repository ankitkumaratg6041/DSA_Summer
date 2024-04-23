#include <iostream>
using namespace std;

class Hero {
    private:
        int health;
        char level;

    public:
        // default constructor
        Hero() {
            cout << "Default constructor called" << endl;
        }

        // parameterized constructor
        Hero(int health){
            this->health = health;
        }

        void print(){
            cout << level << endl;
        }
        int getHealth(){
            return health;
        }
        char getLevel(){
            return level;
        }
        void setHealth(int health){
            this->health = health;
        }
        void setLevel(char level){
            this->level = level;
        }

};

int main(void){
    cout << "Before initializing the object of type Hero" << endl;
    Hero h;
    cout << "After default constructor" << endl;

    cout << endl << "accessing data members using .dot operator" << endl;
    h.setLevel('A');
    h.setHealth(10);
    cout << "Level: " << h.getLevel() << endl;
    cout << "Health: " << h.getHealth() << endl;

    cout << endl;
    Hero *h1 = new Hero();
    cout << "Accessing data members using -> operator" << endl;
    h1->setLevel('B');
    h1->setHealth(11);
    cout << "Level: " << h1->getLevel() << endl;
    cout << "Health: " << h1->getHealth() << endl;

    cout << "Accessing data members using deference * operator and .dot operator" << endl;
    (*h1).setLevel('C');
    (*h1).setHealth(12);
    cout << "Level: " << (*h1).getLevel() << endl;
    cout << "Health: " << (*h1).getHealth() << endl;
    




    return 0;
}