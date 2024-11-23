
#include <iostream>

int main(void)
{
    std::string hiBrain = "HI THIS IS BRAIN";
    
    std::string *ptr = &hiBrain;
    std::string &ref = hiBrain;

    std::cout << "\033[48;5;32m"
              << "string " << &hiBrain << " " << std::endl 
              << "ptr    " << &ptr << " " << std::endl
              << "ref    " << &ref
              << "\033[0m" << std::endl;
    std::cout << "\033[48;5;34m"
              << "string " << hiBrain << " " << std::endl 
              << "ptr    " << ptr << " " << std::endl
              << "ref    " << ref
              << "\033[0m" << std::endl;
    return (0);
}