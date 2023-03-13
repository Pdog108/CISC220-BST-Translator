/*
 * BST.cpp
 *
 *  Created on: Mar 30, 2022
 *      Authors: Patrick Harris, Jake Ravett
 */


#include "BST.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

BST::BST() {
	root = NULL;
}
BST::BST(string s, string l) {
	root = new TNode(s,l);
}

/*
 * The insert method (the foundation of BSTs). It takes
as input the acronym (s) and the definition of the acronym (l). it returns a bool – true if a new
node is inserted, and false if the acronym string s is already in the tree.
*/
bool BST::insert(string s,string l) {
	TNode *place = new TNode(s,l);
	TNode *current = root;
	if(current == NULL) {
		//if the current node is NULL
		root = place;
		place -> printNode(); //call the printNode() function
		return true;
	}
	else {
		while (current != NULL) {
			//adding/inserting on the left side of the tree
			if(s < current -> data -> abbr) {
				if(current -> left == NULL){
					//if current's left is NULL
					current -> left = place;
					current -> left -> parent = current;
					setHeight(place); //call the setHeight() function
					return true;
				}
				else {
					current = current -> left;
				}
			}
			//adding/inserting on the right side of the tree
			else if(s > current -> data -> abbr) {
				if(current -> right == NULL) {
					//if current's right is NULL
					current -> right = place;
					current -> right -> parent = current;
					setHeight(place); //call the setHeight() function
					return true;
				}
				else {
					current = current -> right;
				}
			}
			else {
				if(current -> data -> abbr == s) {
					return false;
				}
			}
		}
	}
}

/*
The find method (almost identical to the insert method, only it
returns the node containing the data to be found and NULL otherwise). This method takes the
acronym string s as input parameter and finds that acronym in the tree, returning the node if it
is successfully found, and NULL otherwise.
*/
TNode *BST::find(string s) {
	if(root == NULL) {
		//if the Root node is NULL that means that the tree is empty and if that's the case then you return NULL because nothing is in the tree
		return NULL;
	}
	else {
		TNode *current = root;
		while(true) {
			if(current -> data -> abbr == s) {
				return current;
			}
			else {
				if(s > current -> data -> abbr) {
					if(current -> right == NULL) {
						return NULL;
					}
					current = current -> right;
				}
				else if(s < current -> data -> abbr) {
					if(current -> left == NULL) {
						return NULL;
					}
					current = current -> left;
				}
			}
		}
	}
}

/*
This method sets the height field of nodes in the tree. It is called
every time you insert a node. That node’s height is 1. You must then work your way up the tree (by going
to each of the inserted node’s ancestors) and updating their heights. Note that the height of a node is
determined as follows: a node’s height is the larger of its left and right children’s heights plus one. So, for
instance, to determine the height of node n, look at the height of node n’s left child (3) and the height of
node n’s right child (5). The right child’s height is larger, with 5. Add 1. The height of node n is 6. For
more details, please watch the binary search tree videos.
*/
void BST::setHeight(TNode *tmp) {
	int left_height = 0;
	int right_height = 0;
	if(tmp -> left != NULL) { //if the left node is not NULL
		left_height = tmp -> left -> height; //should eqaul height of left child.  This points to the left node's height.
	}
	if(tmp -> right != NULL) { //if the right node is not NULL
		right_height = tmp -> right -> height; //should equal the height of the right child. This points to the right node's height
	}
	if(left_height > right_height) {
		tmp -> height = left_height += 1;
	}
	else {
		tmp -> height = right_height += 1;
	}
	if(tmp -> parent == NULL) {
		return;
	}
	setHeight(tmp -> parent);
}
void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}

//The in-order traversal (again, short)
void BST::printTreeIO(TNode *tmp) {
	if(tmp == NULL) {
		return;
	}
	else {
	//recursion on left-hand-side
	printTreeIO(tmp -> left);
	//print
	tmp -> printNode();
	//recursion on right-hand-side
	printTreeIO(tmp -> right);
	}
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

/*
The pre-order traversal (this method should be short – in essence
3 lines and a stopping condition)
*/
void BST::printTreePre(TNode *tmp) {
	if(tmp == NULL) {
		return;
	}
	else {
	//print
	tmp -> printNode();
	//recursion on left-hand-side
	printTreePre(tmp -> left);
	//recursion on right-hand-side
	printTreePre(tmp -> right);
	}
}

void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

/*
The post-order traversal (REALLLY LONG – nah, just kidding
– another short one)
*/
void BST::printTreePost(TNode *tmp) {
	if(tmp == NULL) {
		return;
	}
	else {
	//recursion on left-hand-side
	printTreePost(tmp -> left);
	//recursion on right-hand-side
	printTreePost(tmp -> right);
	//print
	tmp -> printNode();
	}
}
void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();  // for testing, comment back in
		delete(tmp);
	}
}

/*
The removeNoKid method removes the node tmp from
the tree, assuming tmp has no kids
*/
TNode *BST::removeNoKids(TNode *tmp) {
	if(tmp -> parent -> left == tmp) {
		tmp -> parent -> left = NULL;
		setHeight(tmp); //call the setHeight() function
	}
	else if(tmp -> parent -> right == tmp) {
		tmp -> parent -> right = NULL;
		setHeight(tmp);
	}
	return tmp;
}

/*
The remove_one_kid method. The
leftFlag indicates whether the node’s child is either the left child or the right child, and tmp is the node
to be removed.
*/
TNode *BST::removeOneKid(TNode *tmp,bool leftFlag) {
	TNode *Parent = tmp -> parent;
	TNode *returnValue = tmp;
	if (leftFlag == true) {
		//removing the link to the left node
		TNode *Child = tmp -> left;
		if((Parent -> right -> data -> abbr == tmp -> data -> abbr) || (Parent -> right -> data -> meaning == tmp -> data -> meaning)) {
			tmp -> parent -> right = Child;
			returnValue = tmp -> parent;
			delete (tmp);
		}
		if((Parent -> left -> data -> abbr == tmp -> data -> abbr) ||(Parent -> left -> data -> meaning == tmp -> data -> meaning)) {
			tmp -> parent -> left = Child;
			returnValue = tmp -> parent;
			delete(tmp);
		}
	}
	else {
		//removing the link to the right node
		TNode *Child = tmp -> right;
		if((Parent -> right -> data -> abbr == tmp -> data -> abbr) || (Parent -> right -> data -> meaning == tmp -> data -> meaning)) {
			tmp -> parent -> right = Child;
			returnValue = tmp -> parent;
			delete(tmp);
		}
		if((Parent -> left -> data -> abbr == tmp -> data -> abbr) || (Parent -> left -> data -> meaning == tmp -> data -> meaning)) {
			tmp -> parent -> left = Child;
			returnValue = tmp -> parent;
			delete(tmp);
		}
	}
}

/*
The remove method (This isn’t that bad – it’s finding the to be
removed node (and that will be the node returned, eventually). If the node has 0 children, call
removeNoKids. If it has 1 child, call removeOneKid. If it has 2 nodes, find the node that will
replace the node to be removed, copy its data into that node’s data section, and then either call
removeNoKids or removeOneKid with that node whose data you just copied. (again, watch the
videos for more information!) When done, return the node that was removed.
*/
TNode *BST::remove(string s) {
	TNode *node = find(s);
	if(node -> left != NULL && node -> right != NULL) { //removing if the node has two kids
		TNode *current = node -> left;
		while(current -> right != NULL) {
			current = current -> right;
		}
		node -> data = current -> data;
		if(current -> left == NULL && current -> right == NULL) {
			removeNoKids(current); //call the removeNoKids() function
		}
		else if(current -> left != NULL && current -> right == NULL) {
			removeOneKid(current, true);
		}
		else {
			removeOneKid(current, false);
		}
	}
	else if(node -> left != NULL && node-> right == NULL) {
		removeOneKid(node, true);
	}
	else if(node -> right != NULL && node -> left == NULL) {
		removeOneKid(node, false);
	}
	else {
		removeNoKids(node);
	}
	return node;
}
