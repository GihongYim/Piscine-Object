#ifndef __ILONGER_HPP__
#define __ILONGER_HPP__

#include <string>

class ILogger
{
public:
    virtual void write(std::string) = 0;
    virtual ~ILogger();
};

#endif