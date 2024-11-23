#include "weapon.hpp"

void Weapon::setType(const std::string &type) {this->type = type;}

Weapon::Weapon(const std::string weaponType) {
    setType(weaponType);
}

Weapon::~Weapon() {
    std::cout << "\033[38;5;196m" + type << " broke...\033[0m" << std::endl; 
}

std::string &Weapon::getType() {return (type);}