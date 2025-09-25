#include <iostream>
#include "singetons.hpp"
#include "../ex00/Person.hpp"
#include "../ex00/Course.hpp"
#include "../ex00/Room.hpp"

using StudentList = ObjectList<Student*>;
using StaffList = ObjectList<Staff*>;
using CourseList = ObjectList<Course*>;
using RoomList = ObjectList<Room*>;

int main()
{
    Student* student1 = new Student("Student 1");
    Student* student2 = new Student("Student 2");
    Staff* staff1 = new Staff("Staff 1");
    Staff* staff2 = new Staff("Staff 2");
    Course* course1 = new Course("Course 1");
    Course* course2 = new Course("Course 2");
    Room* room1 = new Room();
    Room* room2 = new Room();

    StudentList studentList = StudentList::instance();
    StaffList staffList = StaffList::instance();
    CourseList courseList = CourseList::instance();
    RoomList roomList = RoomList::instance();

    std::cout << "Students:" << std::endl;
    for (const auto& student : studentList.getAllObjects()) {
        std::cout << "- " << student-getName() << std::endl;
    }

    std::cout << "Staffs:" << std::endl;
    for (const auto& staff : StaffList::instance().getAllObjects()) {
        std::cout << "- " << staff->getName() << std::endl;
    }

    std::cout << "Courses:" << std::endl;
    for (const auto& course : CourseList::instance().getAllObjects()) {
        std::cout << "- " << course->getName() << std::endl;
    }

    std::cout << "Rooms:" << std::endl;
    for (const auto& room : RoomList::instance().getAllObjects()) {
        std::cout << "- Room ID: " << room->getID() << std::endl;
    }

    // Clean up
    delete student1;
    delete student2;
    delete staff1;
    delete staff2;
    delete course1;
    delete course2;
    delete room1;
    delete room2;

    return 0;
}