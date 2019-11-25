#pragma once
#include "TreeNode.h"

#include <fstream>
#include <vector>
#include <map>
#include <iostream>

void print2DUtil(TreeNode* root, int space);
void print2D(TreeNode* root);
string encoder(map<string, string> letterCodes, string userString);
string decoder(string userString);
map<string, string> fileParser(ifstream& inFile);
void buildTree();

