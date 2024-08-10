#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact();
    void setFirstName(const std::string &fn);
    void setLastName(const std::string &ln);
    void setNickName(const std::string &Nn);
    void setPhoneNumber(const std::string &pn);
    void setDarkestSecret(const std::string &ds);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    int index;
};

#endif