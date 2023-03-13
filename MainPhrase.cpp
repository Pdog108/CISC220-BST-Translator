/*
 * MainPhrase.cpp
 *
 *  Created on: Mar 30, 2022
 *      Authors: Patrick Harris, Jake Ravett
 */

#include <iostream>
#include "Abbr.hpp"
using namespace std;

int main() {

//Part 1: before you can test this, write the printTreeIO,
//the printTreePree, and printTreePost methods for the BST.
//Note: you can't test these until you write the insert
//method.

//Part 2:
//Write the insert method, focusing on inserting nodes
//to the left.
//
//Then comment out part 2 to test.  Note that
//the heights will all be 1.  This is because you haven't
//written the add_heights method yet.
	cout <<"******Part 2 - testing left***********"<<endl;
	Abbr *abbr = new Abbr("Testleft.txt",2);
	cout << "************************************" << endl;



//Part 3:
//Modify the insert method so that it allows you to
//also insert nodes to the right.  Once you've successfully
//modified the insert method, uncomment out this part and
//test the insert method again (Note that the comments at
//the beginning are for clearing out the tree and deleting
//the abbr object.

	abbr->tree->clearTree();
	delete abbr;
	cout <<endl<< "********* Part3: Testing right *********" << endl;
	abbr = new Abbr("Testright.txt",2);
	cout << "********End Part 3 *****************" << endl;


//Part 4:
//Write the add_heights method and test everything up to this point.
//Make sure your heights and mine are the same.


//Part 5:
//Uncomment out the left-right test below, and run it.  Make sure your output
//and mine match so far.

	abbr->tree->clearTree();
	delete abbr;
	cout << endl<<"********* Part 5: Testing leftright ********" << endl;
	abbr = new Abbr("TestLeftRight.txt",2);
	cout << "**********End Part 5 ***************" << endl;


//Part 6:
//Now write your find method.  This should be very similar to your insert
//method, with the difference being that you never insert a new node, but,
//instead, either return the node in the tree containing the data you are finding,
//or, alternatively, returning NULL if the data doesn't exist in the tree.
//Once you've written, test uncomment out and test part 6, below.

	cout <<endl<<"***********Part 6:  Testing Find ************" << endl;
	TNode *tmp = abbr->tree->find("LY");
	tmp->printNode();

	tmp = abbr->tree->find("SAA");
	tmp->printNode();

	tmp = abbr->tree->find("DMI");
	tmp->printNode();
	cout << "**********End Part 6 **************************" << endl;

//
//Part 7:
//Now write your 3 remove methods.  When you have them written, uncomment out
//Part 7 below to test.
	cout << endl<<"*********Part 7: Testing Remove***************************" << endl;
	cout << "Removing no kids ('LY')"<< endl;
	abbr->tree->remove("LY");
	abbr->tree->printTreeIO();
	abbr->tree->printTreePre();
	abbr->tree->printTreePost();

	cout << "************************************" << endl;
	cout << "Removing one kid ('SAA')"<< endl;
	abbr->tree->remove("SAA");
	abbr->tree->printTreeIO();
	abbr->tree->printTreePre();
	abbr->tree->printTreePost();

	cout << "************************************" << endl;
	cout << "Removing two kid ('DMI')"<< endl;
	abbr->tree->remove("DMI");
	abbr->tree->printTreeIO();
	abbr->tree->printTreePre();
	abbr->tree->printTreePost();
	cout <<"************End Part 7 *******************" << endl;

//
//Part 8:
//Testing the big tree!
	cout << "*************************Part 8 *********************" <<endl;
	//abbr->tree->clearTree();

	//delete abbr;
	cout << "********* Testing leftright ********" << endl;
	Abbr *abbrTree = new Abbr("abbr.txt",1);
	abbrTree->Interface();
	return 0;
}
