#include "Zombie.hpp"

int main() {
	std::string	name;
	name = "stack";

	Zombie	zombie_s(name);
	Zombie	*zombie_h;

	zombie_h = newZombie("heap");
	randomChump("heap");
	zombie_h->announce();
	delete zombie_h;
	return (0);
}
