#pragma once
#include <string>

using namespace std;

/* TreeNode struct*/

struct TreeNode 
{
	string letter;
	TreeNode* left = NULL;
	TreeNode* right = NULL;

	TreeNode()
	{
		letter = "";
	}

	TreeNode(string newLetter)
	{
		letter = newLetter;
	}
};