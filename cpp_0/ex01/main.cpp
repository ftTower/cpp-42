#include "phonebook.hpp"

int main()
{
    PhoneBook  phoneBook;
    std::string     cmd;

    if (MAX_CONTACTS > __INT_MAX__ || MAX_CONTACTS < 1)
        return (std::cout << "\033c" << "Please enter a MAX_CONTACTS beetween 1 and" << __INT_MAX__, 1);
    std::cout << "\033c" << "\033[48;5;208m" << "PHONEBOOK" << std::endl  << "\033[0m";
    while(1)
    {
        std::cout << "CHOOSE BETWEEN : " << "ADD SEARCH EXIT" << std::endl;
        std::cin >> cmd;
        if (cmd == "ADD" || cmd == "add") phoneBook.addContact(phoneBook.getContact()); 
        else if (cmd == "SEARCH" || cmd == "search") phoneBook.searchContact();
        else if (cmd == "EXIT" || cmd == "exit") break;
    }
    return (0);
}