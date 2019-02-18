// Author: Maciej Majchrzak
// Student Number: G00332746
// References: https://web.microsoftstream.com/video/e5e7f5d8-3d2f-4115-9eaa-d9b1d6a91c4e

#include <stdio.h>
#include <math.h>
#include <stdint.h> // 32 bit int to store

unsigned int primes[] = {
	    2,   3,   5,   7,  11,  13,  17,  19,  23,  29 
	,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71 
	,  73,  79,  83,  89,  97, 101, 103, 107, 109, 113 
	, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173 
	, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229 
	, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281 
	, 283, 293, 307, 311 
};

int main(int argc, char *argv[]){
	// Long doubles for precision (numbers won't get rounded)
	long double cubeRoot;
	long double fraction;
	long double multiply;

	for(int i = 0; i < 64; i++){
		cubeRoot = cbrtl( (long double) primes[i] ); // get prime cube roots
		fraction = cubeRoot - floorl(cubeRoot);	// get rid of numbers before the decimal point

		multiply = fraction * 0x100000000; // shift decimal place
		multiply = floorl(multiply); // get rid of stuff after decimal point

		printf("%3d -> %03.6LG -> %03.6LG -> %08x \n", primes[i], cubeRoot, fraction, (uint32_t ) multiply); // print
	}

	return 0;
}
