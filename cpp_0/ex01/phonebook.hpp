#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

#ifndef MAX_CONTACTS
#define MAX_CONTACTS 8
#endif

class PhoneBook {

private:
    Contact contacts[MAX_CONTACTS];
    int index;
    int totalContacts;

public:
    PhoneBook();
    void    displayMenu(bool display_top);
    void    addContact(const Contact &contact);
    Contact getContact() const;
    void    searchContact() const;
    void    displaySearchMenu(bool full_info) const;
    void    displaySearchContacts() const;
    int     getSearchPos() const;
    void    displayContact(int pos) const;
    std::string getInput() const;
};

#endif