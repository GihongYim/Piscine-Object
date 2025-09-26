#pragma once

#include "Form.hpp"
#include "Room.hpp"
#include "Course.hpp"

#include <string>
#include <vector>

class Course;

class Person
{
private:
	std::string _name;
	Room* _currentRoom;
public:
	Person(std::string p_name) : _name(p_name), _currentRoom(nullptr) {}
	Room* room() {return (_currentRoom);}
};

class Staff : public Person
{
private:

public:
	Staff(std::string p_name) : Person(p_name) {}
	void sign(Form* p_form) { p_form->execute(); }
};


class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;

public:
	Student(std::string p_name) : Person(p_name) {}
	void attendClass(Classroom* p_classroom) { p_classroom->enter(this); }
	void exitClass();
	void graduate(Course* p_course);
};

// child class of Staff 
class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
	
public:
	void receiveForm(Form* p_form);
};

class Secretary : public Staff
{
private:

public:
	Form* createForm(FormType p_formType);
	void archiveForm();
};

class Professor : public Staff
{
private:
	Course* _currentCourse;

public:
	void assignCourse(Course* p_course);
	void doClass();
	void closeCourse();
};