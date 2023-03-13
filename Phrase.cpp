/*
 * Phrase.cpp
 *
 *  Created on: Mar 30, 2022
 *      Authors: Patrick Harris, Jake Ravett
 */
#include <iostream>
#include <string>
#include "Phrase.hpp"
using namespace std;

Phrase::Phrase(string s, string l) {
	abbr = s;
	meaning = l;
}

Phrase::Phrase() {
	abbr = "";
	meaning = "";
}
