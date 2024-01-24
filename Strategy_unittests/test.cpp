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

TEST(TestCaseName, TestName) {

    std::string actualOutput = RunSystemCommandWithInputAndGetOutput("Strategy_and_Null_pattern_worksheet.exe", "/n");

    std::cout << actualOutput;

    std::string expectedOutput = "No attack strategy set.\nNo attack strategy set.\nNo attack strategy set.\nShooting with a bow and arrow!\nAttacking with a sword!\nCasting a magic spell!\n";
    EXPECT_EQ(actualOutput, expectedOutput);
}

TEST(TestCaseName, TestName1) {


    EXPECT_TRUE(false);
}