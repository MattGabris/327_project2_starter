/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "constants.h"
//============================================================================
//	stuff you will need
//============================================================================

typedef std::string string;

//TODO define a structure to track words and number of times they occur
//TODO add a global array of entry structs (global to this file)
//TODO add variable to keep track of next available slot in array

typedef struct wordStruct {
	string word;
	int count;
} wordStruct;

wordStruct wordArray[100];

int nextOpenSlot = 0;

//TODO define all functions in header file

//zero out array that tracks words and their occurrences
void clearArray(){
	for (int i = 0; i < nextOpenSlot; i++){
		wordArray[i].word = "";
		wordArray[i].count = 0;
	}
}

//how many unique words are in array
int getArraySize() {
	return nextOpenSlot;
}

//get data at a particular location (The word itself at index i)
std::string getArrayWordAt(int i){
	return wordArray[i].word;
}

//get data at a particular location (How many of the word at index i)
int getArrayWord_NumbOccur_At(int i){
	return wordArray[i].count;
}

// ------------------------------ FILE I/O ------------------------------

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	if (myfstream.is_open() != true){
		return false;
	}
	return true;
}












//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!




























