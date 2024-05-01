#ifndef __SALARIEDEMPLOYEE_HPP__
#define __SALARIEDEMPLOYEE_HPP__

#include <string>

class ISalariedEmployee
{
public:
    virtual void registerNonWorkingHour(std::string reason);
};
#endif