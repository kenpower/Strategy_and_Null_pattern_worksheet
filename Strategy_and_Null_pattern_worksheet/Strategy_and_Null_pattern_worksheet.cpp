#include <iostream>

class Knight {
public:
    std::string attack() {
        return "Attacking with a sword!\n";
    }
};

class Archer {
public:
    std::string attack() {
        return "Shooting with a bow and arrow!\n";
    }
};

class Wizard {
public:
    std::string attack() {
        return "Casting a magic spell!\n";
    }
};

void charactersAttack() {
    Knight knight;
    Archer archer;
    Wizard wizard;

    std::cout << archer.attack(); 
    std::cout << knight.attack(); 
    std::cout << wizard.attack();

}

class AttackStrategy {
public:
    virtual std::string attack() = 0;
};

class Character {
protected:
    AttackStrategy* attackStrategy;

public:
    Character() : attackStrategy(nullptr) {}

    void setAttackStrategy(AttackStrategy* strategy) {
        attackStrategy = strategy;
    }

    std::string attack() {
        if (attackStrategy) {
            return attackStrategy->attack();
        }
        else {
            return "No attack strategy set.\n";
        }
    }
};


void charactersAttackwithStrategy() {
    Character knight;

    while (true) {
        char c;
        std::cout << "What weapon do you want the knight to have?\n";
        std::cout << "1=bow-arrow, 2=sword or 3=magic\n";

        std::cin >> c;
        // uncomment these lines
        //if(c== '1')
        //    knight.setAttackStrategy(/*??????*/);
        //if (c == '2')
        //    knight.setAttackStrategy(/*??????*/);
        //if (c == '3')
        //    knight.setAttackStrategy(/*??????*/);

        std::cout << knight.attack();
    }

}


int main() {
    charactersAttack();

    std::cout << "\n===============================================================";
    std::cout << "\n============Now with dynamnic Weapons==========================";
    std::cout << "\n===============================================================\n";


    charactersAttackwithStrategy();
}
