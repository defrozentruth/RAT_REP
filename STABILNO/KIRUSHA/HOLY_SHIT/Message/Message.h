#pragma once

class Message{
public:
    enum Level{
        Game,
        Info,
        Error
    };
    virtual Level get_level() = 0;
};