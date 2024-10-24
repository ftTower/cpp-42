#include "wrongAnimal.hpp"

wrongAnimal::wrongAnimal(){this->type = "default";};
wrongAnimal::~wrongAnimal(){};

void	wrongAnimal::makeSound(void) const {
	std::cout << "MEEEUuuHuuuuhHHHHH" << std::endl;
}

wrongCat::wrongCat(){};
