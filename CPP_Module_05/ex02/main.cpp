#include "Bureaucrate.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat highRank("HighRank", 1); //  :D
        Bureaucrat midRank("MidRank", 50);  //  :|
        Bureaucrat lowRank("LowRank", 150); // :(
        
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm roboForm("office");
        PresidentialPardonForm presForm("criminal");
        
        highRank.signForm(shrubForm); // :D
        midRank.signForm(roboForm);   // :D
        lowRank.signForm(presForm);   // :(
        
        highRank.executeForm(shrubForm);  // :D
        midRank.executeForm(roboForm);    // :D
        lowRank.executeForm(presForm);    // :( 

        RobotomyRequestForm unSignedRoboForm("unSignedOffice");
        try {
            highRank.executeForm(unSignedRoboForm); //  :( 
        } catch (const AForm::FormNotSignedException &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        for (int i = 0; i < 5; ++i) {
            std::cout << "Attempt " << i + 1 << ": ";
            highRank.executeForm(roboForm); // :(
        }

        highRank.executeForm(presForm);  //:D

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}