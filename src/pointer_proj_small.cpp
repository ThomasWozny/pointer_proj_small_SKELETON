//============================================================================
// Name        : pointer_proj_small.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#include "../includes/constants.h"
#include "../includes/stringmanip.h"
#include "../includes/fileio.h"


int main(int argc, char *argv[]) {	

	if (argc == HELP_NUMBER_ARGUMENTS && *argv[0] == HELP_CHAR) {
			cout << HELP_STRING1 << endl;
			cout << HELP_STRING2 << endl;
			return SUCCESS;
		}
	else if (argc != EXPECTED_NUMBER_ARGUMENTS) {
			cout << HELP_STRING2 << endl;
			return FAIL_WRONG_NUMBER_ARGS;
		}

		string input = argv[1];
		string output = argv[2];
		string tag = argv[3];
		string replacement = argv[4];

		string contents = "";
		readFile(input, contents);

		char *pcontents = &contents[0];
		char *ptag = &tag[0];
		char *pReplacement = &replacement[0];
		int cnt = KP::findNumbOccurrences(pcontents, ptag);

		int amount = KP::amountOfMemoryToAllocateForNewString(contents.length(), cnt, tag.length(), replacement.length());

		char *pheap = new char[amount];
		memset(pheap, 0, amount * sizeof(char));

		int replace = KP::replace(pcontents, pheap, ptag, pReplacement);
		if (replace != SUCCESS) {
			return replace;
		}

		int write = writeFile(output, pheap);
		if (write != SUCCESS) {
			return write;
		}

		if (pheap) {
			delete[] pheap;
			pheap = 0;
		}

		return SUCCESS;

}
