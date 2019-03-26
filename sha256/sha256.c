// Author: Maciej Majchrzak
// SHA256 - Secure Hash Algorithm
// References:

// Input / Output header file.
#include <stdio.h>
// For using fixed bit length integers.
#include<stdint.h>

// Functions
void sha256();

int main(int argc, char *argv[]) {
	sha256();
	return 0;
}//main

void sha256(){
	// Message schedule (Section 6.2)
	uint32_t W[64]
	// Working variables (Section 6.2)
	uint32_t a,b,c,d,e,f,g,h;
	// Two temporary variables
	uint32_t T1, T2;

	// The hash value (Section 6.2)
	// The values come from Section 5.3.3
}//shar256()
