#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "new zombie was created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "zombie " << _name << " was destroyed" << std::endl;
}

void	Zombie::announce() {
	std::cout << _name << ": Moar brainz!..." << std::endl;
}

void 	Zombie::set_name(std::string &name) {
	_name = name;
}
