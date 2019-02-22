#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]){
	uint32_t a = 1;
	uint32_t b = 2;
	
	printf(" a: %08x\n b: %08x\n", a, b);

	printf(" &: %08x\n", (a&b));
	printf(" |: %08x\n", (a|b));
	printf(" ^: %08x\n", (a^b));
	printf(" ~: %08x\n", (~a));
	printf("<<: %08x\n", (a<<1));
	printf(">>: %08x\n", (a>>1));
	
	return 0;

}
