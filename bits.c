#include <stdio.h>
#include <stdint.h>

// Print in binary
void binPrint(uint32_t x) {
	int i;
	uint32_t one = 1;

	for(i = 0; i < 32; i++)
		if((one << (31 - i)) & x)
			printf("1");
		else
			printf("0");
}

int main(int argc, char *argv[]){
	// 32 bit integers
	uint32_t a = 1;
	uint32_t b = 2;
	
	printf(" a: %08x\n b: %08x\n", a, b);

	printf(" &: %08x\n", (a&b)); // aligns bits, checks for bits set, if not then result will be 0
	printf(" |: %08x\n", (a|b)); // is either bit set in a, b or both
	printf(" ^: %08x\n", (a^b)); // when both are set
	printf(" ~: %08x\n", (~a)); // takes all bits and flips them
	printf("<<: %08x\n", (a<<1)); // shift bits in a towards left
	printf(">>: %08x\n\n", (a>>1)); // shift bits in a towards right
	
	printf("   a: ");
	binPrint(a);
	printf("\n");

	printf("   b: ");
	binPrint(b);
	printf("\n");

	printf(" a&b: ");
	binPrint(a&b);
	printf("\n");

	printf(" a|b: ");
	binPrint(a|b);
	printf("\n");

	printf(" a^b: ");
	binPrint(a^b);
	printf("\n");

	printf("  ~a: ");
	binPrint(~a);
	printf("\n");

	printf("a<<1: ");
	binPrint(a<<1);
	printf("\n");

	printf("a>>1: ");
	binPrint(a>>1);
	printf("\n");

	return 0;

}
