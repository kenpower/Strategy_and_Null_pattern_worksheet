#include "pch.h"
#include <iostream>
#include <sstream>
#include <cstdio>


// Function to run an external system command with input and capture its output
std::string RunSystemCommandWithInputAndGetOutput(const char* command, const char* input) {
    std::string output;
    const int BUFFER = 1280;
    char buffer[BUFFER];

    
    FILE* pipe = _popen(command, "r");
    if (!pipe) {
        return "Error executing command.";
    }

    // Provide input to the system command
    fprintf(pipe, "%s", input);
    fclose(pipe);

    pipe = _popen(command, "r");
    if (!pipe) {
        return "Error executing command.";
    }

    while (!feof(pipe)) {
        if (fgets(buffer, BUFFER, pipe) != nullptr) {
            output += buffer;
        }
    }

    _pclose(pipe);
    
    return output;
}

TEST(WholeApplication, CorrectOutput) {

    std::string actualOutput = RunSystemCommandWithInputAndGetOutput("Strategy_and_Null_pattern_worksheet.exe", "/n");

    std::cout << actualOutput;

    std::string expectedOutput = "Shooting with a bow and arrow!\nAttacking with a sword!\nCasting a magic spell!\n";
    EXPECT_EQ(actualOutput, expectedOutput);
}

#include "../Strategy_and_Null_pattern_worksheet/strategy_characters.h"
TEST(Strategy_Characters, InitialAttack) {
    Character knight;
    Character archer;
    Character wizard;

    EXPECT_STREQ("No attack strategy set.\n", knight.attack().c_str()); 
    EXPECT_STREQ("No attack strategy set.\n", archer.attack().c_str()); 
    EXPECT_STREQ("No attack strategy set.\n", wizard.attack().c_str()); 
}

TEST(Strategy_Characters, DynamicAttack) {
    Character knight;
    Character archer;
    Character wizard;

    archer.setAttackStrategy(new BowAndArrowAttack());
    knight.setAttackStrategy(new SwordAttack());
    wizard.setAttackStrategy(new MagicAttack());


    EXPECT_STREQ("Attacking with a sword!\n", knight.attack().c_str());
    EXPECT_STREQ("Shooting with a bow and arrow!\n", archer.attack().c_str());
    EXPECT_STREQ("Casting a magic spell!\n", wizard.attack().c_str());
}