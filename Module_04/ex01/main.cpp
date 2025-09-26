#include <iostream>
#include "singetons.hpp"
#include "../ex00/Person.hpp"
#include "../ex00/Course.hpp"
#include "../ex00/Room.hpp"

// 타입별 별칭 정의
using StudentList = ObjectList<Student>;
using StaffList   = ObjectList<Staff>;
using CourseList  = ObjectList<Course>;
using RoomList    = ObjectList<Room>;

int main() {
    // 학생 생성 및 추가
    Student* s1 = new Student("Student1");
    Student* s2 = new Student("Student2");
    StudentList& studentList = StudentList::instance();
    studentList.add(s1);
    studentList.add(s2);

    // 교직원 생성 및 추가
    Staff* staff1 = new Staff("Staff1");
    Staff* staff2 = new Staff("Staff2");
    StaffList& staffList = StaffList::instance();
    staffList.add(staff1);
    staffList.add(staff2);

    // 강의 생성 및 추가
    Course* course1 = new Course("Course1");
    Course* course2 = new Course("Course2");
    CourseList& courseList = CourseList::instance();
    courseList.add(course1);
    courseList.add(course2);

    // 강의실 생성 및 추가
    Room* room1 = new Room();
    Room* room2 = new Room();
    RoomList& roomList = RoomList::instance();
    roomList.add(room1);
    roomList.add(room2);

    // 학생 확인
    std::cout << "[Students]" << std::endl;
    for (auto* student : studentList.getAllObjects()) {
        std::cout << "Student added!" << std::endl;
    }

    // 교직원 확인
    std::cout << "[Staffs]" << std::endl;
    for (auto* staff : staffList.getAllObjects()) {
        std::cout << "Staff added!" << std::endl;
    }

    // 강의 확인
    std::cout << "[Courses]" << std::endl;
    for (auto* course : courseList.getAllObjects()) {
        std::cout << "Course added!" << std::endl;
    }

    // 강의실 확인
    std::cout << "[Rooms]" << std::endl;
    for (auto* room : roomList.getAllObjects()) {
        std::cout << "Room added!" << std::endl;
    }

    return 0;
}
