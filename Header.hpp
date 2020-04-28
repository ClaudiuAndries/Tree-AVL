#pragma once

class AVL
{
	int value;
public:
	AVL* left, *right;
	void SetValue(int);
	int GetValue();
};

int GetHight(AVL*);
int CalculGrade(AVL*);
AVL* InsertNode(AVL* root, int val);
void BreadthFirstSearch(AVL* root);
void DepthFirstSearch(AVL* root);

AVL* RotationLeft(AVL*);
AVL* RotationRight(AVL*);

AVL* DeleteNode(AVL*, int);
AVL* GetMin(AVL* root);

void Search(AVL* root, int value);
void IterativeSearch(AVL* root, int value);

AVL* InsertNodeIterative(AVL* root, int val);