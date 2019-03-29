#include <stdio.h>
#include <stdint.h>

// Represents a message block.
union msgblock {
    uint8_t e[64];
    uint32_t t[16];
    uint64_t s[8];
};

// A flag for where we are in reading the file.
enum status {READ, PAD0, PAD1, FINISH};

int main(int argc, char *argv[]) {
    union msgblock M;

    uint64_t nobits = 0;
    uint64_t nobytes;

    enum status S = READ;
    
    FILE* f;
    f = fopen(argv[1], "r");

    while(S == READ) {
        nobytes = fread(M.e, 1, 64, f);
        printf("Read: %211u bytes\n", nobytes);
	nobits = nobits + (nobytes * 8);

        if(nobytes < 56) {
            printf("I have found a block with less than 56 bytes!\n");
            M.e[nobytes] = 0x80;

            while(nobytes < 56) {
                nobytes = nobytes + 1;
                M.e[nobytes] = 0x00;
            }//while
            M.s[7] = nobits;
            S = FINISH;
        }//if
        else if (nobytes < 64) {
            S = PAD0;
            M.e[nobytes] = 0x80;
            while (nobytes < 64) {
                nobytes = nobytes + 1;
                M.e[nobytes] = 0x00;
            }//while
        } //else if
        else if(feof(f)) {
            S = PAD1;              
        }//else if
    }//while

    if (S == PAD0 || S== PAD1) {
        for (i = 0; i < 56; i++)
            M.e[i] = 0x00;

        M.s[7] = nobits;
    }//if

    if (S == PAD1)
        M.e[0] = 0x80; 

    fclose(f);
    
    for(int i = 0; i < 64; i++)
        printf("%x ", M.e[i]);

        printf("\n");
	return 0;
}//main()
