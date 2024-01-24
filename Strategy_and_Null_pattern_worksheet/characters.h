#pragma once
#include<string>

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
