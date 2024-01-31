#pragma once
#include <string>
// Strategy Interface
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
