#include <iostream>
class Knight {
public:
    void attack() {
        std::cout << "Attacking with a sword!" << std::endl;
    }
};

class Archer {
public:
    void attack() {
        std::cout << "Shooting with a bow and arrow!" << std::endl;
    }
};

class Wizard {
public:
    void attack() {
        std::cout << "Casting a magic spell!" << std::endl;
    }
};


// Strategy Interface
class AttackStrategy {
public:
    virtual void attack() = 0;
};

// Concrete Strategies
class SwordAttack : public AttackStrategy {
public:
    void attack() override {
        std::cout << "Attacking with a sword!" << std::endl;
    }
};

class BowAndArrowAttack : public AttackStrategy {
public:
    void attack() override {
        std::cout << "Shooting with a bow and arrow!" << std::endl;
    }
};

class MagicAttack : public AttackStrategy {
public:
    void attack() override {
        std::cout << "Casting a magic spell!" << std::endl;
    }
};


class Character {
protected:
    AttackStrategy* attackStrategy;

public:
    Character() : attackStrategy(nullptr) {}

    void setAttackStrategy(AttackStrategy* strategy) {
        attackStrategy = strategy;
    }

    void attack() {
        if (attackStrategy) {
            attackStrategy->attack();
        }
        else {
            std::cout << "No attack strategy set." << std::endl;
        }
    }
};

void charactersAttack() {
    Knight knight;
    Archer archer;
    Wizard wizard;

    knight.attack(); 
    archer.attack(); 
    wizard.attack();

}

void charactersAttackwithStrategy() {
    Character knight;
    Character archer;
    Character wizard;

    knight.attack(); // Initial attack strategy for Knight
    archer.attack(); // Initial attack strategy for Archer
    wizard.attack(); // Initial attack strategy for Wizard

    // Change attack strategies dynamically
    knight.setAttackStrategy(new BowAndArrowAttack());
    archer.setAttackStrategy(new SwordAttack());
    wizard.setAttackStrategy(new MagicAttack());

    knight.attack(); // New attack strategy for Knight
    archer.attack(); // New attack strategy for Archer
    wizard.attack(); // New attack strategy for Wizard
}


int main() {
    charactersAttack();

    charactersAttackwithStrategy();
}
