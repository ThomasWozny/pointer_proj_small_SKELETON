#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../includes/constants.h"
#include "../includes/fileio.h"

using namespace std;

const bool COULD_OPEN_FILE = true;
const bool COULD_NOT_OPEN_FILE = false;


bool openFile(fstream& myfile, const std::string& myFileName, ios_base::openmode mode){

	myfile.open(myFileName.c_str(), mode);

	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	return COULD_OPEN_FILE;
}


void closeFile(std::fstream& myfile){
	if (myfile.is_open()){
		myfile.close();
	}
}


int writeFile(std::string &filename,char *contents){
	fstream myfile;

		ios_base::openmode mode = ios_base::out;
		bool file_opened = openFile(myfile, filename, mode);

		if (!file_opened) {
			return FAIL_CANNOT_OPEN_FILE;
		}

		if (contents == NULL) {
			return INVALID_NULL_PTR_DETECTED;
		}

		myfile << contents;
		closeFile(myfile);

		return SUCCESS;
}


int readFile(std::string &filename,std::string &contents){
	fstream myfile;
	ios_base::openmode mode = ios_base::in;
	bool file_opened = openFile(myfile, filename, mode);

	if (!file_opened) {
		return FAIL_CANNOT_OPEN_FILE;
	}

	getline(myfile, contents);

	closeFile(myfile);

	return SUCCESS;
}
