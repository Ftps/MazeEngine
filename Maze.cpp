#include "Maze.hpp"

Stack::Stack()
{
	size = 0;
	stack = NULL;
}

Stack::Stack(std::array<int, 2> Pos)
{
	size = 1;
	stack = (stackable*)malloc(sizeof(stackable));
	stack->pos[0] = Pos[0];
	stack->pos[1] = Pos[1];
	stack->prev = NULL;
}

Stack::~Stack()
{
	stackable *aux;

	while(stack != NULL){
		aux = stack;
		stack = stack->prev;
		free(aux);
	}
}



std::array<int, 2> Stack::pop()
{
	stackable *aux = stack;
	std::array<int, 2> ret;

	if(aux == NULL){

	}
	else{
		stack = stack->prev;
		ret = aux->pos;
		free(aux);
	}

	return ret;
}

void Stack::push(std::array<int, 2> pos)
{
	stackable *aux = (stackable*)malloc(sizeof(stackable));
	aux->prev = stack;
	aux->pos = pos;
	stack = aux;
}

void Stack::printStack()
{
	stackable *aux = stack;
	int i = 0;

	while(aux != NULL){
		std::cout << i << ": " << aux->pos[0] << ", " << aux->pos[1] << std::endl;
		aux = aux->prev;
	}
}




Maze::Maze(std::array<int, 2> Size)
{
	size = Size;

	lab = (int**)malloc(sizeof(int)*size[1]);
	for(int i = 0; i < size[1]; ++i){
		lab[i] = (int*)calloc(sizeof(int), size[0]);
	}
}

Maze::~Maze()
{
	for(int i = 0; i < size[1]; ++i){
		free(lab[i]);
	}
	free(lab);
}

void Maze::generate()
{
	int sw = 1<<(rand()%4);
	int ew;

	
}
