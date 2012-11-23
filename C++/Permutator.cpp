/*
 * File: Permutation.cpp
 * -----------------
 * This program will generates the permutation for the given string inputted 
   by users, and it will avoid generating duplicated charaters. 
 */
//Library Inclusion

#include <iostream>
#include "simpio.h"
#include <string>
using namespace std;

//Function Prototype
void RecursivePermute(string prefix, string rest, string checkPrefix);
void ListPermutations(string str);

//Main
int main() {
	cout << "Please enter a string.\n";
	string inputString;
	getline(cin, inputString);
	cout << endl;
	ListPermutations(inputString);

	return 0;
}

/*
 * Function: ListPermutations
 * Usage: Used in main. 
 * ---------------------------------
 * This function is a simple wrapper function that calls a subsidiary function to solve the more general case.
*/
void ListPermutations(string str) {
	RecursivePermute("", str, "");
}
/*
 * Function: RecursivePermut
 * Usage: Used in ListPermutations. 
 * ---------------------------------
 * This function is used to generate all the permutations for the given string by using recursion.
*/

void RecursivePermute(string prefix, string rest, string checkPrefix) {
	if (rest == "") {
		cout << prefix << endl;
	}	
	else {
		for (int i = 0; i < rest.length(); i++) {
			string newPrefix = prefix + rest[i];
			if (newPrefix != checkPrefix){
				//check if they have the same character.
				checkPrefix = newPrefix;
				string newRest = rest.substr(0, i) + rest.substr(i+1);
				RecursivePermute(newPrefix, newRest, checkPrefix);
			}
		}
	}
}