#include<stdio.h>

int isprime(unsigned int test){
	unsigned int i;

	for(i = 2; i < test; i++) {
		if(test % i == 0) {
			return 0;
		}
	}
	return 1;

}
int main(int argc, char *argv[]){
	unsigned int test=653;
	
	if(isprime(test))
		printf("%d prime\n", test);
	else
		printf("%d not prime\n", test);
						
	return 0;
}
