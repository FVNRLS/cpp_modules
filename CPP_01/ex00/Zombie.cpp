#include "Zombie.hpp"

Zombie::Zombie(std::string &name) {
	_name = name;
	std::cout << "zombie " << _name << " was created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "zombie " << _name << " was destroyed" << std::endl;
}

void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}