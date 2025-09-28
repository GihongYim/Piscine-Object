#include "../ex00/Person.hpp"
#include "../ex00/Form.hpp"

#include <iostream>

int main()
{
    Secretary secretary("Alice");
    Headmaster headmaster("Bob");

    Form* form1 = secretary.createForm(FormType::CourseFinished);
    Form* form2 = secretary.createForm(FormType::NeedMoreClassRoom);
    Form* form3 = secretary.createForm(FormType::NeedCourseCreation);
    Form* form4 = secretary.createForm(FormType::SubscriptionToCourse);

    headmaster.receiveForm(form1);
    headmaster.receiveForm(form2);
    // headmaster.receiveForm(form3);
    headmaster.receiveForm(form4);

    std::cout << "--- execute forms ---" << std::endl;
    form1->execute();
    form2->execute();
    form3->execute();
    form4->execute();

    // delete form1;
    // delete form2;
    // delete form3;
    // delete form4;

    return 0;
}