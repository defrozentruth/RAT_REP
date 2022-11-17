#include "Logger.hpp"
#include "fstream"

#pragma once

class FileLog: public Logger{
    std::ofstream file;
public:
    FileLog(std::string name);
    ~FileLog();
    void output(Message* msg) override;
};