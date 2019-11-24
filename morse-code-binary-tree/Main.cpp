#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/* This is under construction still but basically this is the bones of the TreeNode */
struct TreeNode {
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

map<string, string> letterCodes;
TreeNode* rootNode = new TreeNode("NULL");

/* This function outputs a horizontal representation of the binary tree to the console*/
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
		if (userString[i] != ' ') {
			oneLetter = userString[i];
			string oneCode = letterCodes[oneLetter];
			encodedString += oneCode + ' ';
			cout << "One code for " << oneLetter << " is: " << oneCode << endl;
		}
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
		if (userString[i] == '.')
		{
			traverser = traverser->left;
		}

		else
		{
			traverser = traverser->right;
		}
	}

	decodedString = traverser->letter;

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


		cout << endl << endl;
	}

}



// Driver code  

int main() {
	//Step 1) create all variables needed in the main
	char userChoice;
	string userString, userStringFormatted, encodedString, decodedString;
	ifstream inFile("morse.txt");
	map<string, string> letterCodes;

	//Step 2) import the letters and associated codes into a hash map
	letterCodes = fileParser(inFile);

	//Step 3) create the BST which stores the letters and associated dots and dashes into the bst appropriately
	buildTree();

	//Step 4) allow a menu for encoding and decoding
	cout << "Menu ==> " << endl;
	cout << "a. encode " << endl;
	cout << "b. decode " << endl;
	cout << "==> ";
	cin >> userChoice;

	switch (userChoice) {
		case('a'):
			cout << "What is the string you would like to encode (please only use letters a-z lowercase) ==>";
			cin >> userString;
			encodedString = encoder(letterCodes, userString);
			cout << "The encoded string is: " << encodedString << endl;
			break;

		case('b'):
			cout << "What is the string you would like to decode (please only use dots and dashes) ==>";
			cin >> userString;
			decodedString = decoder(userString);
			cout << "The decoded string is: " << decodedString << endl;
			break;

		default:
			cout << "You have given invalid input " << endl;
			break;
	}

	system("PAUSE");
	return 0;
}
