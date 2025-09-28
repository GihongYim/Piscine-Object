#include "Person.hpp"


Form* Secretary::createForm(FormType p_formType)
{
	switch (p_formType)
	{
		case FormType::CourseFinished:
			return new CourseFinishedForm();
		case FormType::NeedMoreClassRoom:
			return new NeedMoreClassRoomForm();
		case FormType::NeedCourseCreation:
			return new NeedCourseCreationForm();
		case FormType::SubscriptionToCourse:
			return new SubscriptionToCourseForm();
		default:
			return (nullptr);
	}
}
