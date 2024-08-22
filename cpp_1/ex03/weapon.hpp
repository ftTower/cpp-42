
#include <iostream>

class Weapon {

    private:
    std::string type;

    public:
    std::string getType(const std::string type);
    void        setType(const std::string &type);

};