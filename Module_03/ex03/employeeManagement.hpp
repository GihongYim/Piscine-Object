#ifndef __EMPLOYEEMANAGEMENT_HPP__
#define __EMPLOYEEMANAGEMENT_HPP__

#include <vector>
#include "employee.hpp"

class EmployeeManager 
{
private:
    std::vector<Employee*> employeed;
public:
    void addEmployee(Employee* employee) 
    {
        employeed.push_back(employee);
    }

    void removeEmployee(Employee* employee)
    {
        for (int i = 0; i < employeed.size(); i++) {
            if (employee == employeed[i]) {
                employeed.erase(employeed.begin() + i);
                break;
            }
        }
    }

    void excuteWorkday()
    {
        for (int i = 0; i < employeed.size(); i++) {
            employeed[i]->excuteWorkday();
        }
    }

    void calculatePayroll()
    {

    }
};

#endif