#include "Bureaucrate.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Création des bureaucrates avec différentes notes
        Bureaucrat highRank("HighRank", 1); //  :D
        Bureaucrat midRank("MidRank", 50);  //  :|
        Bureaucrat lowRank("LowRank", 150); // :(
        
        // Création des formulaires avec des cibles
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm roboForm("office");
        PresidentialPardonForm presForm("criminal");
        
        // Test de la signature des formulaires
        highRank.signForm(shrubForm); // :D
        midRank.signForm(roboForm);   // :D
        lowRank.signForm(presForm);   // :(
        
        // Test de l'exécution des formulaires après signature
        highRank.executeForm(shrubForm);  // :D
        midRank.executeForm(roboForm);    // :D
        lowRank.executeForm(presForm);    // :( 

        // Exécution des formulaires non signés
        RobotomyRequestForm unSignedRoboForm("unSignedOffice");
        try {
            highRank.executeForm(unSignedRoboForm); //  :( 
        } catch (const AForm::FormNotSignedException &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test de la réussite ou de l'échec du RobotomyRequestForm avec une chance de succès
        for (int i = 0; i < 5; ++i) {
            std::cout << "Attempt " << i + 1 << ": ";
            highRank.executeForm(roboForm); // :(
        }

        // Test de l'exécution des formulaires par un bureaucrate ayant la bonne note
        highRank.executeForm(presForm);  //:D

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}