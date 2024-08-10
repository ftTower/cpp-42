#include "phonebook.hpp"

Contact::Contact() {}

//setters
void   Contact::setFirstName(const std::string &fn) {firstName = fn;}
void    Contact::setLastName(const std::string &Ln) {lastName = Ln;}
void    Contact::setNickName(const std::string &Nn) {nickName = Nn;}
void    Contact::setPhoneNumber(const std::string &Pn) {phoneNumber = Pn;}
void    Contact::setDarkestSecret(const std::string&Ds) {darkestSecret = Ds;}

//getters
std::string Contact::getFirstName() const {return firstName;}
std::string Contact::getLastName() const {return lastName;}
std::string Contact::getNickName() const {return nickName;}
std::string Contact::getPhoneNumber() const {return phoneNumber;}
std::string Contact::getDarkestSecret() const {return darkestSecret;}

