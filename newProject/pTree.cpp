#include "pTree.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <windows.h>
using namespace std;

pTree::pTree()
{
	this->isLeaf = false;
	for (int i = 0; i < 28; i++)
		this->children[i] = NULL;

	for (int i = 0; i < 128; i++)
		this->character[i] = nullptr;
}
void pTree:: write_in_file()
{
	map<string, string>::iterator itr;
	fstream ofs;
	ofs.open("file.txt", ios::out | ios::trunc);
	for (itr = myMap.begin(); itr != myMap.end(); ++itr) {
		ofs << itr->first<<endl <<itr->second<<endl;
		}
	ofs.close();
}
void pTree::load_from_file()
{
	string word,definition;
	ifstream readFile("file.txt");
	while (!readFile.eof()) {
		getline(readFile, word);
		getline(readFile, definition);
		myMap.insert(pair<string, string>(word, definition));
	}
	readFile.close();
}
void pTree::inserting(string word, string definition)
{
   myMap.insert(pair<string, string>(word, definition));
   map<string, string>::iterator itr;
   fstream ofs;
   ofs.open("file.txt", ios::out | ios::trunc);
   for (itr = myMap.begin(); itr != myMap.end(); ++itr) {
	   ofs << itr->first << endl << itr->second<<endl;
   }
   ofs.close();

   
}

void pTree::searchAuto(string prefix)
{
	map<string, string>::iterator itr;
	bool flag,goodflag=false;
	string myWord;
	for (itr = myMap.begin(); itr != myMap.end(); ++itr) {
		for (int i = 0; i < prefix.size(); i++)
		{
			if (prefix[i] == itr->first[i])
			{
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			cout << '\t' << itr->first << '\n';
			goodflag = true;

		}
		else if (flag == false)
		{
			continue;
		}
	}

	if (goodflag == false)
	{
		cout <<endl<< "Word is Not found!!"<<endl ;
	}
	else {

		cout << "Enter the word to display its definition : ";
		cin >> myWord;
		map<string, string>::iterator itr2;
		for (itr2 = myMap.begin(); itr2 != myMap.end(); ++itr2) {
			
			if (myWord == itr2->first)
			{
				cout << '\t' << itr2->first << " : " << itr2->second;

			}
			else 
			{
				continue;
			}
		}
	}
}
void pTree::deleted( string word)
{
	
	map<string, string>::iterator itr2;
	for (itr2 = myMap.begin(); itr2 != myMap.end(); ++itr2) {

		if (word == itr2->first)
		{
			
			myMap.erase((word));
			myMap.erase((itr2->second));
			break;

		}
		else
		
			continue;
		
	}
	write_in_file();
}
void pTree::search(string word)
{
	bool x=true;
	pTree* curr = this;
	for (int i = 0; i < word.size(); i++)
	{
		if (curr == nullptr)
			x = false;
		else
		{
			curr = curr->character[word[i]];
		}

		// if string is invalid (reached end of path in Trie)

	}

	curr = this;
	if (x == true)
	{
		map<string, string>::iterator itr;

		for (itr = myMap.begin(); itr != myMap.end(); ++itr) {
			if (itr->first == word) {
				cout << '\t' << itr->first
					<< '\t' << itr->second << '\n';
			}
			else
				continue;
			}
		cout << endl;
	}
	else if (x == false)
	{
		cout << "word not found";
	}
}

bool pTree::haveChildren(pTree const* curr)
{
	for (int i = 0; i < 128; i++)
		if (curr->character[i])
			return true;   

	return false;
}

