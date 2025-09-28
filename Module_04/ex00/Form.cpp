#include "Form.hpp"

#include <iostream>

void CourseFinishedForm::execute()
{
	if (_isSigned)
		std::cout << "The course has been finished." << std::endl;
	else
		std::cout << "The form is not signed yet." << std::endl;
}

void NeedMoreClassRoomForm::execute()
{
	if (_isSigned)
		std::cout << "Need more classrooms." << std::endl;
	else
		std::cout << "The form is not signed yet." << std::endl;
}

void NeedCourseCreationForm::execute()
{
	if (_isSigned)
		std::cout << "Need to create a new course." << std::endl;
	else
		std::cout << "The form is not signed yet." << std::endl;
}

void SubscriptionToCourseForm::execute()
{
	if (_isSigned)
		std::cout << "Subscription to a course." << std::endl;
	else
		std::cout << "The form is not signed yet." << std::endl;
}
