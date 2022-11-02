#include <fstream>
#include "../Logger/Logger.h"

class FileLogger: public Logger{
    std::ofstream file;
public:
    FileLogger(const std::string& name = "log.txt");
    void print(Message* msg) override;
    ~FileLogger() final;
};