/*
 * TNode.cpp
 *
 *  Created on: Mar 30, 2022
 *      Authors: Patrick Harris, Jake Ravett
 */

#include <iostream>
#include <string>
#include "TNode.hpp"
using namespace std;

TNode::TNode(string s, string l) {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	data = new Phrase(s,l);
}
TNode::TNode() {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	data = new Phrase();
}
TNode::~TNode(){
	//cout <<"Deleting "<<data->abbr<<endl;  // comment in for testing purposes
}
void TNode::printNode() {
	cout << data->abbr<<","<<data->meaning<<","<<height<<endl;
}
