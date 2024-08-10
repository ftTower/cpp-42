#include "phonebook.hpp"

PhoneBook::PhoneBook() : index(0), totalContacts(0) {}


void    PhoneBook::addContact(const Contact &contact)
{
    int pos = index % MAX_CONTACTS;
    contacts[pos] = contact;
    if (index == MAX_CONTACTS - 1)
        index = 0;
    if (totalContacts < MAX_CONTACTS)
        totalContacts++;
    index++;
}

Contact PhoneBook::getContact() const
{
    Contact newContact;
    
    std::string buf;
    std::cout << "\033c" << "Enter First Name : " << std::endl;
    std::cin >> buf;
    newContact.setFirstName(buf);
    std::cout << "Enter Last Name : " << std::endl;
    std::cin >> buf;
    newContact.setLastName(buf);
    std::cout << "Enter Nick Name : " << std::endl;
    std::cin >> buf;
    newContact.setNickName(buf);
    std::cout << "Enter Phone Number : " << std::endl;
    std::cin >> buf;
    newContact.setPhoneNumber(buf);
    std::cout << "Enter Darkest Secret : " << std::endl;
    std::cin >> buf;
    newContact.setDarkestSecret(buf);
    return (newContact.index = index , newContact);
}

void   PhoneBook::displaySearchMenu(bool full_info) const
{
    std::cout << "\033c" << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|";
    if (full_info)
        std::cout << std::setw(10) << "Phone N." << "|"
                  << std::setw(10) << "Darkest." << "|";
    std::cout << std::endl;
    std::cout << "---------------------------------------------";
    if (full_info)
        std::cout << "--------------------";
    std::cout << std::endl;
}

void    PhoneBook::displaySearchContacts() const
{
    for (int pos = 0; pos < totalContacts; pos++)
    {
        std::cout << std::setw(10) << contacts[pos].index << "|"
                    << std::setw(10) << (contacts[pos].getFirstName().length() > 10 ? contacts[pos].getFirstName().substr(0, 9) + "." : contacts[pos].getFirstName()) << "|"
                    << std::setw(10) << (contacts[pos].getLastName().length() > 10 ? contacts[pos].getLastName().substr(0, 9) + "." : contacts[pos].getLastName()) << "|"
                    << std::setw(10) << (contacts[pos].getNickName().length() > 10 ? contacts[pos].getNickName().substr(0, 9) + "." : contacts[pos].getNickName()) << "|"
                    <<std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

void    PhoneBook::displayContact(int pos) const
{
    if (pos < 0 || pos > MAX_CONTACTS - 1)
        return ;
    displaySearchMenu(true);
    std::cout << std::setw(10) << pos << "|"
              << std::setw(10) << contacts[pos].getFirstName() << "|" 
              << std::setw(10) << contacts[pos].getLastName() << "|"
              << std::setw(10) << contacts[pos].getNickName() << "|"
              << std::setw(10) << contacts[pos].getPhoneNumber() << "|"
              << std::setw(10) << contacts[pos].getDarkestSecret() << "|" << std::endl;
}

int    PhoneBook::getSearchPos() const
{
    std::string pos;
    int num = 0;
    
    std::cout <<  "Please enter a number beetwen 0 and " << totalContacts - 1 << std::endl;
    std::cin >> pos;
    for (int index = 0; pos[index]; index++)
    {
        if (!isdigit(pos[index]))
            return (std::cout << "\033c" << "\033[48;5;160m" <<  "Invalid input. Please enter a valid number." << std::endl << "\033[0m", getSearchPos());
        num = (num * 10) + (pos[index] - '0');
    }
    if (num < 0 || num > MAX_CONTACTS - 1 || num > totalContacts - 1)
        return (std::cout << "\033c" <<  "\033[48;5;160m" << "Number out of range. Please enter a number between 0 and " << totalContacts << std::endl << "\033[0m", getSearchPos());
    return (num);
}

void    PhoneBook::searchContact() const 
{
    if (!totalContacts)
        return (std::cout << "\033c" << "\033[48;5;160m" << "Please add a Contact before all" << std::endl << "\033[0m", (void)0);
    displaySearchMenu(false);
    displaySearchContacts();
    displayContact(getSearchPos());
}