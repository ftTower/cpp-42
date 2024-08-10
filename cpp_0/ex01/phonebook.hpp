#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>

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
    void    addContact(const Contact &contact);
    void    searchContact() const;
    void    displaySearchMenu() const;
    void    displaySearchContacts() const;
    int    getSearchPos() const;
    void    displayContact(int pos) const;
};

#endif