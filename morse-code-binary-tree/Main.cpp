#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/* This function takes a user's string and turns it into a series of dots (with each letter's dot and dashses separated by a space) */
string encoder(map<string, string> letterCodes, string userString) {
	string encodedString;
	for (int i = 0; i < userString.size(); ++i) {
		string oneLetter;
		if (userString[i] != ' ') {
			oneLetter = userString[i];
		}

		else {
			string oneCode = letterCodes[oneLetter];
			encodedString += oneCode + ' ';
			cout << "One code for " << oneLetter << " is: " << oneCode << endl;
		}
	}

	return encodedString;
}

/* This function takes a user's already encoded string of dots and dashes and returns a string of the letter value for each code */
string decoder(string userString) {
	string decodedString;
	return decodedString;
}

/* This function takes a file and parses through it and puts everything into a map with letter as key and dots/dash combo as value */
map<string, string> fileParser(ifstream& inFile) {
	string lineString;
	string letter;
	map<string, string> letterCodes; 
	while (!inFile.eof()) {
		inFile >> letter;

		while (inFile.peek() != '\n') {
			inFile >> lineString;
		}

		letterCodes[letter] = lineString;
		cout << "Letter:" << letter << endl;
		cout << "String:" << lineString << endl;
	}

	return letterCodes;
}

int main() {
	//Step 1) create all variables needed in the main
	char userChoice;
	string userString, userStringFormatted, encodedString, decodedString;
	ifstream inFile("morse.txt");
	map<string, string> letterCodes;

	//Step 2) import the letters and associated codes into a hash map
	letterCodes = fileParser(inFile);

	//Step 3) create the BST which stores the letters and associated dots and dashes into the bst appropriately

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
