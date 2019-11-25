#include "Functions.h"

using namespace std;

map<string, string> letterCodes;
TreeNode* rootNode = new TreeNode("NULL");

void print2DUtil(TreeNode* root, int space)
{
	// Base case  
	if (root == NULL)
		return;

	// Increase distance between levels  
	space += 10;

	// Process right child first  
	print2DUtil(root->right, space);

	// Print current node after space  
	// count  
	cout << endl;
	for (int i = 10; i < space; i++)
		cout << " ";
	cout << root->letter << "\n";

	// Process left child  
	print2DUtil(root->left, space);
}

/* wrapper */
void print2D(TreeNode* root)
{
	// Pass initial space count as 0  
	print2DUtil(root, 0);
}



/* This function takes a user's string and turns it into a series of dots (with each letter's dot and dashses separated by a space) */
string encoder(map<string, string> letterCodes, string userString) {
	string encodedString;
	for (int i = 0; i < userString.size(); ++i) {
		string oneLetter;
		if (userString[i] == ' ')
		{
			encodedString += "/ ";
			continue;
		}
			
		oneLetter = tolower(userString[i]);
		string oneCode = letterCodes[oneLetter];
		encodedString += oneCode + ' ';

	}

	return encodedString;
}

/* This function takes a user's already encoded string of dots and dashes and returns a string of the letter value for each code */
string decoder(string userString)
{
	string decodedString;

	TreeNode* traverser = rootNode;

	for (int i = 0; i < userString.size(); i++)
	{
		if (isspace(userString[i]) && traverser != rootNode)
		{
			decodedString += traverser->letter;
			traverser = rootNode;
			continue;
		}

		if (isspace(userString[i]))
		{
			continue;
		}
			

		if (userString[i] == '/')
		{
			decodedString += " ";
			continue;
		}

		if (userString[i] == '.')
		{
			if (traverser->left == NULL)
			{
				return "String not in letter library";
			}

			traverser = traverser->left;
		}

		else if (userString[i] == '_')
		{
			if (traverser->right == NULL)
			{
				return "String not in letter library";
			}

			traverser = traverser->right;
		}

		else
		{
			return "Invalid character in string";
		}
	}

	decodedString += traverser->letter;
	return decodedString;




}

/* This function takes a file and parses through it and puts everything into a map with letter as key and dots/dash combo as value */
map<string, string> fileParser(ifstream& inFile) {
	string lineString;
	string letter;
	while (!inFile.eof()) {
		inFile >> letter >> lineString;
		letterCodes[letter] = lineString;
		/*cout << "Letter:" << letter << endl;
		cout << "String:" << lineString << endl;*/
	}

	return letterCodes;
}


/* This function builds the binary tree containing all the letters organized by their morse code (left node = dot || right node = dash*/
void buildTree()
{
	map<string, string>::iterator it;


	TreeNode* traverser;

	for (it = letterCodes.begin(); it != letterCodes.end(); it++)
	{
		traverser = rootNode;

		for (int i = 0; i < it->second.size(); i++)
		{
			if (it->second[i] == '.')
			{
				if (traverser->left == NULL)
				{
					traverser->left = new TreeNode("-1");
				}


				traverser = traverser->left;
			}

			else
			{
				if (traverser->right == NULL)
				{
					traverser->right = new TreeNode("-1");
				}


				traverser = traverser->right;
			}
		}

		traverser->letter = it->first;
	}

}