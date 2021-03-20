#include <string.h>
#include <iostream>
#include "../includes/constants.h"
#include "../includes/stringmanip.h"

using namespace std;

namespace KP{

	int amountOfMemoryToAllocateForNewString(int len_src, int numbTagsToReplace, int len_tag, int len_tag_replacement){
		return len_src - (numbTagsToReplace * len_tag) + (numbTagsToReplace * len_tag_replacement) + 1;
	}


	int replace(const char *src, char *new_src, const char *tag, const char *tag_replacement){

		if (src == NULL || new_src == NULL || tag == NULL || tag_replacement == NULL) {
			return INVALID_NULL_PTR_DETECTED;
		}

		int src_len = strlen(src) + 1;
		int tag_len = strlen(tag);
		int rtag_len = strlen(tag_replacement);


		int i = 0;
		int change = 0;
		int delta = 0;

		while (i + delta < src_len){
			cout << "i:" << i << "\t:\'" << *((src + i)) << "new_src" << new_src << endl;
			if(*(src+i+delta) == tag[0]) {
				if (strncmp((src + i) + delta, tag, tag_len) == 0) {
					strncat((new_src + i) + change, tag_replacement, rtag_len);
					change += rtag_len;
					delta += tag_len;
				}
			}
			*((new_src + i) + change) = *((src + i) + delta);
			i++;
		}
		return SUCCESS;
	}

	int findNumbOccurrences(const char *src,  const char *tag) {
		if (src == NULL || tag == NULL) {
					return INVALID_NULL_PTR_DETECTED;
				}

		int lenSrc = strlen(src);
		int lenTag = strlen(tag);
		int count = 0;

		for (int i = 0; i < lenSrc; i++) {
				//zoom along till we find the first char
				if (*(src + i) == tag[0]) {
					//found an a, lets see if it could be the start of a beautiful thing
					if (strncmp((src + i), tag, lenTag) == 0) {
						//got it woohoo, now what?
						cout << "Found \'"<<tag<<"\' in \'" << src << "\'" << endl;
						count++;
					}
				}
			}
		return count;
	}
}
