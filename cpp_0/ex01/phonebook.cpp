#include "phonebook.hpp"

PhoneBook::PhoneBook() : index(0), totalContacts(0) {}

void    PhoneBook::addContact(const Contact &contact)
{
    int pos = index % MAX_CONTACTS;
    contacts[pos] = contact;
    if (index == MAX_CONTACTS)
        index = 0;
    if (totalContacts < MAX_CONTACTS)
        totalContacts++;
    index++;
}


void   PhoneBook::displaySearchMenu() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void    PhoneBook::displaySearchContacts() const
{
    for (int pos = 0; pos < totalContacts; pos++)
    {
        std::cout << std::setw(10) << (contacts[pos].getFirstName().length() > 10 ? contacts[pos].getFirstName().substr(0, 9) + "." : contacts[pos].getFirstName()) << "|"
                    << std::setw(10) << (contacts[pos].getLastName().length() > 10 ? contacts[pos].getLastName().substr(0, 9) + "." : contacts[pos].getLastName()) << "|"
                    << std::setw(10) << (contacts[pos].getNickName().length() > 10 ? contacts[pos].getNickName().substr(0, 9) + "." : contacts[pos].getNickName()) << "|"
                    <<std::endl;
    }
}

void    PhoneBook::displayContact(int pos) const
{
    if (pos < 0 || pos > MAX_CONTACTS)
        return ;
    
}

int    PhoneBook::getSearchPos() const
{
    int pos = -1;
    while(pos < 0 || pos > MAX_CONTACTS)
    {
        std::cout << "Please enter a number beetwen 0 and " << MAX_CONTACTS << std::endl;
        std::cin >> pos;
    }
    return (pos);
}

void    PhoneBook::searchContact() const 
{
    displaySearchMenu();
    displaySearchContacts();
    displayContact(getSearchPos());
}