#pragma once
#include <string>
// Strategy Interface
class AttackStrategy {
public:
    virtual std::string attack() = 0;
};

// Concrete Strategies
class SwordAttack : public AttackStrategy {
public:
    std::string attack() override {
        return "Attacking with a sword!\n";
    }
};

class BowAndArrowAttack : public AttackStrategy {
public:
    std::string attack() override {
        return "Shooting with a bow and arrow!\n";
    }
};

class MagicAttack : public AttackStrategy {
public:
    std::string attack() override {
        return "Casting a magic spell!\n";
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

    std::string attack() {
        if (attackStrategy) {
            return attackStrategy->attack();
        }
        else {
            return "No attack strategy set.\n";
        }
    }
};
