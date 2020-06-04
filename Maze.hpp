#ifndef MAZE_HPP
#define MAZE_HPP

#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>

enum positions	{	CN_N = 0b00001,
 					CN_S = 0b00010,
 					CN_E = 0b00100,
 					CN_W = 0b01000,
 					CN_V = 0b10000
				};

struct stackable{
	std::array<int, 2> pos;
	stackable *prev;
};

class Stack{
	private:
		stackable *stack;
		int size;

	public:
		Stack();
		Stack(std::array<int, 2> Pos);
		~Stack();

		std::array<int, 2> pop();
		void push(std::array<int, 2> pos);
		void printStack();
};

class Maze : private Stack{
	private:
		std::array<int, 2> size, beg, end;
		int **lab;

	public:
		Maze(std::array<int, 2> Size);
		~Maze();

		void generate();
};

#endif
