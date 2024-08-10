#include "phonebook.hpp"

int main()
{
    PhoneBook  phoneBook;

    if (MAX_CONTACTS > __INT_MAX__ || MAX_CONTACTS < 1)
        return (std::cout << "Please enter a MAX_CONTACTS beetween 1 and" << __INT_MAX__, 1);
    phoneBook.searchContact();
    return (0);
}