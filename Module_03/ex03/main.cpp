#include <iostream>
#include "employeeManagement.hpp"
#include "employee.hpp"

int main() {
    EmployeeManager manager;

    std::cout << "LSP demonstration: EmployeeManager can manage Employee-derived objects." << std::endl;
    // 아래와 같이 Employee의 파생 클래스 객체를 추가하면
    // manager.addEmployee(new TempWorker());
    // manager.addEmployee(new ContractEmployee());
    // manager.addEmployee(new Apprentice());
    // manager.excuteWorkday(); // 모든 Employee 파생 객체의 excuteWorkday()가 호출됨

    std::cout << "(Add Employee-derived objects to manager to see polymorphic behavior.)" << std::endl;
    return 0;
}