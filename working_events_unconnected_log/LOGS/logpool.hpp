#pragma once
#include "message.hpp"
#include <vector>

class LogPool{
    std::vector<Message*> pool;
public:
    LogPool();
    ~LogPool();
    std::vector<Message*> getPool();
};