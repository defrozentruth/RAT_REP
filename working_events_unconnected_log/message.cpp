#include "message.hpp"

    std::ostream& operator<<(std::ostream& os, const Message* elem){
        os  << elem->msg << '\n';
        return os;
    };