#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include<iomanip>
#include "pTree.h"
using namespace std;

int main()
{
	pTree* myTree = new pTree();
	int choice,backOrnot=1;
	string word;
	myTree->load_from_file();
	
	while (backOrnot == 1) {
		system("cls");
		system("Color 0C");
		cout << setw(70) <<endl<< endl << endl << endl << "Semantic Auto Complete System"<<endl;
		cout << setw(65) << endl << "1.Search for a word" << setw(66) << endl 
		<< "2.Insert a new Word " << setw(61)<< endl
		<< "3.Delete a word" << setw(52)<<endl<<"4.Exit"<<endl;
		cout << setw(60)<<endl << "Your choice : " ;
		cin >> choice;

		if (choice == 1)
		{
			system("cls");
			system("Color 01");
			cout << "Enter the Word : ";
			cin >> word;
			myTree->searchAuto(word);
			cout <<endl<< "1.Back" << endl << "2.Exit"<<endl;
			cin >> backOrnot;

		}
		else if (choice == 2)
		{
			string definition;
			system("cls");
			system("Color 05");
			cout << "Enter the Word : ";
			cin >> word;
			cout << "Enter the definition : ";
			cin.ignore();
			getline(cin, definition);
			myTree->inserting(word, definition);
			cout << "Word inserted successfully! ";
			cout <<endl<< "1.Back" << endl << "2.Exit" << endl;
			cin >> backOrnot;
		}
		else if (choice == 3)
		{
			system("cls");
			system("Color 02");
			cout << "Enter the Word to be deleted : ";
			cin >> word;
			myTree->deleted( word);
			cout << "Word deleted successfully! ";
			cout << "1.Back" << endl << "2.Exit" << endl;
			cin >> backOrnot;
		}
		else if (choice == 4)
		{
			backOrnot = 2;
		}
		else
		{
			cout << "Enter the right choice!!"<<endl;
			cout << "1.Back" << endl << "2.Exit" << endl;
			cin >> backOrnot;
		}

	}
	return 0;
	
}