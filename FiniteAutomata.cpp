//============================================================================
// Name        : FiniteAutomata.cpp
// Author      : Tarin Horne
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

const bool DEBUG = true;
const bool T = true;
const bool F = false;

const char alphabet[4] = {
	'a','b','c',' '
};
struct State{
	bool isEndState;
	struct State *NS[4]; //Next State
};
//Defining States
State S[3] = {
	{F,{&S[1],&S[0],&S[2],&S[0]}},
	{T,{&S[0],&S[1],&S[2],&S[1]}},
	{T,{&S[0],&S[2],&S[1],&S[2]}}
};

bool isRecognised(string word);
int isLetter(char letter);

int main() {
	string testWords[12] = {
		"aa bcc b",
		" bca",
		"aabbcc",
		"abc abc",
		"ac",
		"ab ",
		" bc",
		"ac bc ",
		"aaa bbb ccc",
		"k",
		"c b a",
		""
	};
	for(int i = 0; i < 12; i++){
		(isRecognised(testWords[i])) ? cout << "Exists" << "\n" : cout << "Does not Exist" << "\n";
	}
	return 0;
}

bool isRecognised(string word){
	State* current = &S[0];
	int nextState;
	for(unsigned int i = 0; i < word.length(); i++){
		nextState = isLetter(word[i]);
		if(nextState < 0) return false;
		current = current->NS[nextState];
	}
	return current->isEndState;
}

int isLetter(char letter){
	for(int i = 0; i < 4; i++){
		if(letter == alphabet[i]) return i;
	}
	return -1;
}
