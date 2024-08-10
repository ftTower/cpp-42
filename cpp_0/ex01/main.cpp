#include "phonebook.hpp"

int main()
{
    PhoneBook  phoneBook;
    std::string     cmd;

    if (MAX_CONTACTS > __INT_MAX__ || MAX_CONTACTS < 1)
        return (std::cout << "Please enter a MAX_CONTACTS beetween 1 and" << __INT_MAX__, 1);
    std::cout << "PHONEBOOK" << std::endl;
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