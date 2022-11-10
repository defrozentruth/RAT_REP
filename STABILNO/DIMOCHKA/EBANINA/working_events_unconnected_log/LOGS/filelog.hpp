#pragma once

#include "logger.hpp"
#include "fstream"

class FileLogger: public Logger{
    LogPool pool;
    LogType type;
    LogGenerator gen;
    std::ofstream file;
public:
    FileLogger(const std::string& name = "log.txt");
    ~FileLogger();
    void printLog();
    LogType retType();
    void newLog(std::string inpLog);
};