#include <iostream>
#include <string>
#include <iomanip>
// #include <>

class contact
{
    public:
    contact();
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    std::string darkest_secret;
    void display()
    {
        std::cout << "first name : " << first_name << " last name : " << last_name << " phone : " << phone_number << " secret : " << darkest_secret;
    }

};

