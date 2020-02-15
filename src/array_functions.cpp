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
void clearArray() {
	for (int i = 0; i < nextOpenSlot; i++) {
		wordArray[i].word = "";
		wordArray[i].count = 0;
	}
}

//how many unique words are in array
int getArraySize() {
	return nextOpenSlot;
}

//get data at a particular location (The word itself at index i)
std::string getArrayWordAt(int i) {
	return wordArray[i].word;
}

//get data at a particular location (How many of the word at index i)
int getArrayWord_NumbOccur_At(int i) {
	return wordArray[i].count;
}

// ---------------------------------------- FILE I/O ----------------------------------------

/*Keep track of how many times each token seen*/
void processToken(std::string &token) {
	if (nextOpenSlot == 0) {
		wordArray[0].word = token;
		wordArray[0].count++;
		nextOpenSlot++;
	}
	for (int i = 0; i < nextOpenSlot; i++){
		if (token == wordArray[i].word){
			wordArray[i].count++;
		}
		else if (i == nextOpenSlot--){
			wordArray[nextOpenSlot].word = token;
			wordArray[nextOpenSlot].count++;
			nextOpenSlot++;
		}
	}
}

/*take 1 line and extract all the tokens from it
 feed each token to processToken for recording*/
void processLine(std::string &myString) {
	std::istringstream ss(myString);
	while (std::getline(ss, myString, ' ') || std::getline(ss, myString, ',')
			|| std::getline(ss, myString, '.')
			|| std::getline(ss, myString, '!')) {
		processToken(myString);
	}
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
// ----- This was a helpful guide for learning how to properly import lines from files
// ----- https://www.systutorials.com/241686/how-to-process-a-file-line-by-line-in-c/
bool processFile(std::fstream &myfstream) {
	if (myfstream.is_open() != true) {
		return false;
	}
	string str;
	while (std::getline(myfstream, str, '\n')){
		processLine(str);
	}
	return true;
}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in){
	myfile.open(myFileName);
	return true;
}

/*iff myfile is open then close it*/
void closeFile(std::fstream &myfile){
	if (myfile.is_open() == true){
		myfile.close();
	}
}



//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

