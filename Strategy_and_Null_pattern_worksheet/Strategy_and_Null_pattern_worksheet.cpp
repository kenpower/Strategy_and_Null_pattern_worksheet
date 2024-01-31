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
