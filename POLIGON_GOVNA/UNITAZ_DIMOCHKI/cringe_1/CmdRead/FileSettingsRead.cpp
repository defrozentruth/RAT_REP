#include "FileSettingsRead.hpp"
#include <iostream>

FileSettingsRead::FileSettingsRead() {
    LogPool* logger = LogPool::getInstance();

    std::string line;
    std::ifstream file("../settings.txt");

    // TODO [pavelbezpravel]: input validation.

    file >> line;
    associateCmd.insert({line, Up});

    file >> line;
    associateCmd.insert({line, Left});

    file >> line;
    associateCmd.insert({line, Down});

    file >> line;
    associateCmd.insert({line, Right});

    file >> line;
    associateCmd.insert({line, Finish});

    std::cout << "==============\n";

    for (const auto& [str, val] : associateCmd) {
        std::cout << str << " " << val << "\n";
    }
    std::cout << "==============\n";
}

std::map<std::string, Commands> FileSettingsRead::getDirections() {
    return this->associateCmd;
}
