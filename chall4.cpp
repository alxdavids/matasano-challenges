#include <string>
#include <fstream>
#include <iostream>
#include "xor_helper.h"

using namespace std;

int main(int argc, char** argv) {
	ifstream inFile("strings.txt");
	if (!inFile) {
	  	cerr << "File strings.txt not found." << endl;
	  	return -1;
	}

	string line;
    while (getline(inFile, line)) {
    	if (line.empty()) continue;

	    std::string encrypted_hex = line;
		int len = encrypted_hex.length();
		xor_helper x;

		int *count = x.produce_count_array(encrypted_hex);

		// unsigned short possible_char[52] = {0};
		// for (char i='A'; i<='Z'; i++) {
		// 	unsigned short z = i - 0;
		// 	possible_char[z-65] = z;
		// }
		// for (char i='a'; i<='z'; i++) {
		// 	unsigned short z = i - 0;
		// 	possible_char[z-71] = z;
		// }
		unsigned short possible_char[256] = {0};
		for (unsigned short i=0; i<256; i++) {
			possible_char[i] = i;
		}

		x.print_candidates(possible_char, encrypted_hex, len);

		delete [] count;
  	}
}