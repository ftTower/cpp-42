#include "Bureaucrate.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 151);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat keke("Keke", 70);  
        std::cout << keke << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat coco("Coco", 1);
        coco.decrementGrade();  
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat cece("Cece", MAX_GRADE - 1);
        cece.incrementGrade();  
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}