#include "Maze.hpp"

int main(int argc, char* argv[])
{
	std::srand(std::time(nullptr));

	int a = rand()%7;
	std::cout << a << std::endl;
	std::cout << (1<<a) << std::endl;

	return 0;
}
