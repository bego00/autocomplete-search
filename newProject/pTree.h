#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
class pTree
{
public:
	bool isLeaf;
	pTree* character[128];
	pTree* children[28];
	map <string, string> myMap;
	 pTree();
	void inserting(string word, string definition);
	void deleted( string word);
	bool haveChildren(pTree const*);
	void search(string key);
	void searchAuto(string prefix);
	void write_in_file();
	void load_from_file();
	
};

