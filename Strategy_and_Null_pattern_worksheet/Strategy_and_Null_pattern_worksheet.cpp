#include <iostream>
#include "characters.h"
#include "strategy_characters.h"


void charactersAttack() {
    Knight knight;
    Archer archer;
    Wizard wizard;

    std::cout << archer.attack(); 
    std::cout << knight.attack(); 
    std::cout << wizard.attack();

}

void charactersAttackwithStrategy() {
    Character knight;
    Character archer;
    Character wizard;

    std::cout << knight.attack(); // Initial attack strategy for Knight
    std::cout << archer.attack(); // Initial attack strategy for Archer
    std::cout << wizard.attack(); // Initial attack strategy for Wizard

    // Change attack strategies dynamically
    knight.setAttackStrategy(new BowAndArrowAttack());
    archer.setAttackStrategy(new SwordAttack());
    wizard.setAttackStrategy(new MagicAttack());

    std::cout << knight.attack(); // New attack strategy for Knight
    std::cout << archer.attack(); // New attack strategy for Archer
    std::cout << wizard.attack(); // New attack strategy for Wizard
}


int main() {
    charactersAttack();

    //charactersAttackwithStrategy();
}
