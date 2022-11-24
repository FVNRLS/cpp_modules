#include "Zombie.hpp"

int main() {

	Zombie	*zombie_h;

	zombie_h = newZombie("heap");
	zombie_h->announce();
	delete zombie_h;

	std::cout << std::endl;

	randomChump("stack");
	std::cout << std::endl << "Zombie on stack was destroyed INSIDE the randomChump function!" << std::endl;
	return (0);
}
