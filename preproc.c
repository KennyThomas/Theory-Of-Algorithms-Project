#include <stdio.h>
#include <inttypes.h>

#define BYTE uint8_t
#define WORD uint32_t
#define PF PRIX32
#define W 32

union Block{
    BYTE bytes[64];
    WORD words[16];
    uint64_t sixf[8];
};

enum Status{
    READ, PAD, END
};

int next_block(FILE *f, union Block *B, enum Status *S , uint64_t *nobits){
    
    //no. bytes read
    size_t nobytes;

    if(*S == END){
        return 0;
        }
        else if(*S == READ){
        //try to read 64 bytes
        nobytes = fread(B->bytes, 1 , 64 , f);
        //Update total bits read
        *nobits = *nobits + (8 * nobytes);
        if(nobytes == 64){
            return 1;
        } else if(nobytes <= 56){
            B->bytes[nobytes] = 0x80; // in bits: 10000000

            for(nobytes++; nobytes < 56;nobytes++){
                B->bytes[nobytes] = 0x00; // in bits: 00000000
            }

            // Append length of original input
            B->sixf[7] = *nobits;
            //say this is the last block
            *S = END;
        }else{
            B->bytes[nobytes] = 0x80;

            for(nobytes++; nobytes < 64; nobytes++){
                B->bytes[nobytes] = 0x00; // in bits: 00000000
            }
            //Change status to PAD
            *S = PAD;
        }

    }else if (*S == PAD){
        for (nobytes = 0; nobytes <56; nobytes++){
            B->bytes[nobytes] = 0x00; // in bits: 00000000
        }
        //Change status to END
        B->sixf[7] = *nobits;
        *S = END;
    }

    return 1;
}



int main(int argsc , char *argv[]){
    int i;

    union Block B;

    //Total num of bytes read
    uint64_t nobits = 0;

    // Curren Status
    enum Status S = READ;
    //File pointer
    FILE *f;
    //open file from command line
    f = fopen(argv[1], "r");

    //Get the next block
    while(next_block(f, &B, &S, &nobits)){
        for(i = 0; i < 16; i++){
            printf("%08" PF "  " , B.words[i]);
        }
        printf("\n");
    }

    //close file
    fclose(f);
    printf("Total bits read: %d.\n" , nobits);

    return 0;
}