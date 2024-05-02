#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

#include <vector>
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"
class Employee
{
protected:
    int hourlyValue;
public:
    virtual ~Employee() {}
    virtual int excuteWorkday() = 0;
    
};

class TempWorker: protected Employee, IHourlyEmployee
{
private:
    std::vector<int> workingHour;
public:
    void registerWorkingHour(int hour)  {
        workingHour.push_back(hour);
    }   
};

class ContractEmployee: protected Employee, ISalariedEmployee
{
private:
    std::vector<std::string> notWorking;
public:
    void registerNonWorkingHour(std::string reason) {
        notWorking.push_back(reason);
    }
};

class Apprentice: protected Employee, ISalariedEmployee
{
private:
    std::vector<int> schoolHour;
    std::vector<std::string> notWorking;
public:
    void registerNonWorkingHour(std::string reason) {
        notWorking.push_back(reason);
    }

    void schoolHour(int hour) {
        schoolHour.push_back(hour);
    }
};

#endif