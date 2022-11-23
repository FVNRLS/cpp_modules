#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie	zombie_stack(name);
	zombie_stack.announce();
}