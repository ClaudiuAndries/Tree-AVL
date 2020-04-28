#include <iostream>
#include "Header.hpp"

AVL* root = nullptr;

int main()
{
	root = InsertNode(root, 47);
	root = InsertNode(root, 51);
	root = InsertNode(root, 13);
	root = InsertNode(root, 7);
	root = InsertNode(root, 20);
	root = InsertNode(root, 21);
	DepthFirstSearch(root);



	std::cout << std::endl;


	IterativeSearch(root, 7);
	DeleteNode(root, 13);
	DepthFirstSearch(root);
}