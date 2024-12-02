#include "Bureaucrate.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);

        Form formA("FormA", 45, 30);
        Form formB("FormB", 150, 150);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        bob.signForm(formA);
        bob.signForm(formB);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}