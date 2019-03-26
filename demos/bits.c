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

uint32_t rotl(uint32_t x, int n){
	return ((x << n) | (x >> (32 - n)));
}

uint32_t rotr(uint32_t x, int n){
	return ((x << (32 - n)) | (x >> n));
}

int main(int argc, char *argv[]){
	// 32 bit integers
	uint32_t a = 0x428a2f98;
	uint32_t b = 0x71374491;
	
	printf(" a: %08x\n b: %08x\n", a, b); // print in hex values

	printf(" &: %08x\n", (a&b)); // aligns bits, checks for bits set, if not then result will be 0
	printf(" |: %08x\n", (a|b)); // is either bit set in a, b or both
	printf(" ^: %08x\n", (a^b)); // when both are set
	printf(" ~: %08x\n", (~a)); // takes all bits and flips them
	printf("<<: %08x\n", (a<<1)); // shift bits in a towards lefit
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

	printf("a<<3: ");
	binPrint(a<<3);
	printf("\n");

	printf("a>>3: ");
	binPrint(a>>3);
	printf("\n");

	printf("rotl(a,3): ");
	binPrint(rotl(a,3));
	printf("\n");

	printf("rotr(a,3): ");
	binPrint(rotr(a,3));
	printf("\n");

	return 0;

}
