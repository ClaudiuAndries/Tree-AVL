#include <iostream>
#include <queue>
#include <stack>
#include "Header.hpp"

int GetHight(AVL* root)
{
	if (root)
	{
		int MaxLeft  = GetHight(root->left);
		int MaxRight = GetHight(root->right);

		return 1 + (MaxLeft > MaxRight ? MaxLeft : MaxRight);
	}
	else return 0;
}

int CalculGrade(AVL* root)
{
	if (!root) return -1;
	unsigned int gradeLeft = (unsigned int)GetHight(root->left);
	unsigned int gradeRight = (unsigned int)GetHight(root->right);
	return gradeLeft - gradeRight;
}

AVL* InsertNode(AVL* root, int val)
{
	if (root)
	{
		if (val < root->GetValue())
			root->left = InsertNode(root->left, val);
			
		else if (root->GetValue() < val)
			root->right = InsertNode(root->right, val);
	}
	else
	{
		AVL* temp = new AVL;
		temp->left = temp->right = 0;
		temp->SetValue(val);
		root = temp;

	}
	return root;
}

void BreadthFirstSearch(AVL* root)
{
	if (!root) return;
	AVL* current;
	std::queue<AVL*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		current = Q.front();
		Q.push(current->left);
		Q.push(current->right);
		std::cout << current->GetValue() << " ";
	}
	std::cout << std::endl;
}

void DepthFirstSearch(AVL* root)
{
	if (!root) return;

	DepthFirstSearch(root->left);
	std::cout << root->GetValue() << " ";
	DepthFirstSearch(root->right);
}

AVL* RotationLeft(AVL* root)
{
	AVL* temp = root->right;

	root->right = temp->left;
	temp->left = root;
	root = temp;
	return root;
}

AVL* RotationRight(AVL* root)
{
	AVL* temp = root->left;

	root->left = temp->right;
	temp->right = root;
	root = temp;
	return root;
}

AVL* DeleteNode(AVL* root, int value)
{
	if (!root) return nullptr;

	if (value < root->GetValue())
		root->left = DeleteNode(root->left, value);
	else if(root->GetValue() < value)
		root->right = DeleteNode(root->right, value);
	else
	{
		//case Leaf
		if (root->left == root->right)
		{
			delete root;
			root = 0;
		}
		//case 1 leaf
		else if (root->left == nullptr && root->right != nullptr)
		{
			AVL* temp = root;
			root = root->right;
			delete temp;
			temp = 0;
		}
		else if (root->left != nullptr && root->right == nullptr)
		{
			AVL* temp = root;
			root = root->left;
			delete temp;
			temp = 0;
		}
		//case 2 leaf
		else
		{
			AVL* min = GetMin(root);
			root->SetValue(min->GetValue());
			delete min;
			min = 0;
		}

	}
	return root;
}

void AVL::SetValue(int v)
{
	value = v;
}

int AVL::GetValue()
{
	return value;
}

AVL*  GetMin(AVL* root)
{
	while (root->left)
	{
		root = root->left;
	}
	return root;
}

void Search(AVL* root, int value)
{
	if (!root) return;

	if (root->GetValue() < value)
		Search(root->right, value);
	else if (root->GetValue() > value)
		Search(root->left, value);
	else
	{
		std::cout << "S-a gasit valoarea!" << std::endl;
	}
}

void IterativeSearch(AVL* root, int value)
{
	while (root != nullptr)
	{
		if (root->GetValue() < value)
		{
			root = root->right;
			continue;
		}
		else if (root->GetValue() > value)
		{
			root = root->left;
			continue;
		}
		else
		{
			std::cout << "S a gasit valoarea!" << std::endl;
			break;
		}
	}
}

AVL* InsertNodeIterative(AVL* root, int val)
{
	if (root == nullptr)
	{
		AVL* temp = new AVL;
		temp->left = temp->right = 0;
		temp->SetValue(val);
		root = temp;
	}
	else
	{
		while (root)
		{
			if (root->GetValue() > val && root->left != nullptr)
			{
				root = root->left;
				continue;
			}
			else if (root->GetValue() < val && root->right != nullptr)
			{
				root = root->right;
				continue;
			}
			else
			{
				if (root->left != nullptr)
				{
					AVL* temp = new AVL;
					temp->left = temp->right = 0;
					temp->SetValue(val);
					root->right = temp;
				}
				else if (root->left != nullptr)
				{
					AVL* temp = new AVL;
					temp->left = temp->right = 0;
					temp->SetValue(val);
					root->left = temp;
				}
				break;
			}
		}
	}
	return nullptr;
}


