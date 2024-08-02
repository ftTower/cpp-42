#include "phonebook.hpp"
// #include <contacthpp> // Include the necessary header file for the contact class

contact::contact(void) { return; }

const int MAX_CONTACT = 8;

static void menu()
{
    std::cout << std::endl
              << "- ADD" << std::endl
              << "- SEARCH" << std::endl
              << "- EXIT" << std::endl
              << std::endl;
}

contact addContact(void)
{
    contact newContact;
    std::string buffer;

    std::cout << "first name : ";
    getline(std::cin, buffer, '\n');
    newContact.first_name = buffer;
    std::cout << "last name  : ";
    getline(std::cin, buffer, '\n');
    newContact.last_name = buffer;
    std::cout << "phone numb : ";
    getline(std::cin, buffer, '\n');
    newContact.phone_number = buffer;
    std::cout << "darkest secret : ";
    getline(std::cin, buffer, '\n');
    newContact.darkest_secret = buffer;
    return (std::cout << "\033c", newContact);
}

void searchContact(contact phonebook[], int nbr_contact)
{
    int index;

    index = 0;
    std::cout << "\033c";
    while (index < nbr_contact)
    {
        std::cout << phonebook[index].first_name << " ";
        std::cout << phonebook[index].last_name << " ";
        std::cout << phonebook[index].phone_number << " ";
        std::cout << phonebook[index].darkest_secret;
        std::cout << std::endl;
        index++;
    }
}

int main(void)
{
    int contact_index;
  
    int numContact;
  
    contact phonebook[MAX_CONTACT];
    std::string command;

    contact_index = 0;
    numContact = 0;
    std::cout << std::endl
              << "\033[38;5;196m" << "HELLO PHONEBOOK" << "\033[0m" << std::endl;
    while (1)
    {
        menu();
        getline(std::cin, command, '\n');
        if ((command == "EXIT" || command == "exit") && std::cout << "\033c")
            break;
        else if (command == "ADD" || command == "add")
        {
            if (contact_index == MAX_CONTACT)
                contact_index = 0;
            phonebook[contact_index++] = addContact();
            if (numContact < MAX_CONTACT)
                numContact++;   
        }
        else if (command == "SEARCH" || command == "search")
            searchContact(phonebook, numContact);
        else
            std::cout << "command not found" << std::endl;
    }
    return (0);
}