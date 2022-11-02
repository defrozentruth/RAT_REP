#pragma once

enum Level{
    Game,
    Info,
    Error
};

class Message{
public:
    virtual Level get_level() = 0;
};