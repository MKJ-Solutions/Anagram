


//Library Inclusion
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;




//Function Prototype
bool CheckFile();
bool CheckWord(string word_input);


//Main

int main(){
	cout << CheckWord("gjjkhkhlk") << endl;
	cout << CheckWord("johnson") << endl;
}


bool CheckWord(string word_input){
	ifstream myReadFile;
	myReadFile.open("dictionary.txt");
	string check_line;
	if(myReadFile.is_open()){
		while(!myReadFile.eof()){
			getline(myReadFile, check_line);
			if(word_input == check_line){
				return 1;			
			}
		}
	}
	myReadFile.close();
	return 0;	
}


