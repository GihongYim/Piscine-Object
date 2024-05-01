#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"
class Employee
{
protected:
    int hourlyValue;
public:
    int excuteWorkday(){

    }
};

class TempWorker: protected Employee, IHourlyEmployee
{

};

class ContractEmployee: protected Employee, ISalariedEmployee
{

};

class Apprentice: protected Employee, ISalariedEmployee
{

};

#endif