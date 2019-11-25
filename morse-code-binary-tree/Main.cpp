#include "Functions.h"
#include "TreeNode.h"

using namespace std;

// Driver code  

int main() {
	//variables
	char userChoice;
	string userString, userStringFormatted, encodedString, decodedString;
	ifstream inFile("morse.txt");
	map<string, string> letterCodes;

	//import the letters and associated codes into a hash map
	letterCodes = fileParser(inFile);

	//create the BST which stores the letters and associated dots and dashes into the bst appropriately
	buildTree();

	cout << encoder(letterCodes, "Hello World") << endl;
	cout << decoder(".... . ._.. ._.. ___ / .__ ___ ._. ._.. _..") << endl;

	system("PAUSE");
	return 0;
}
