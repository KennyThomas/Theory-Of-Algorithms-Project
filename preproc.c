#include <stdio.h>
#include <inttypes.h>

#define BYTE uint8_t
#define WORD uint32_t
#define PF PRIX32
#define W 32

union Block{
    BYTE bytes[64];
    WORD words[16];
};

int main(int argsc , char *argv[]){
    int i;

    union Block B;

    //Total num of bytes read
    uint64_t nobits = 0;


    //File pointer
    FILE *f;
    //open file from command line
    f = fopen(argv[1], "r");
    //no. of bytes read
    size_t nobytes;

    //read bytes
    nobytes = fread(B.bytes, 1 , 64 , f);
    printf("Read %d bytes. \n" , nobytes);
    //update no of bits read
    nobits = nobits + (8 * nobytes);
    //print the 16 32-bit words.
    for(i = 0; i < 16; i++){
    printf("%08" PF "  " , B.words[i]);
    if ((i + 1) % 8 == 0)
    printf("\n");
    }

    while(!feof(f)){
        nobytes = fread(B.bytes, 1 , 64 , f);
        printf("Read %d bytes. \n" , nobytes);
        nobits = nobits + (8 * nobytes);
          //print the 16 32-bit words.
        for(i = 0; i < 16; i++){
            printf("%08" PF "  " , B.words[i]);
                if ((i + 1) % 8 == 0)
                    printf("\n");
        }
    }

    //close file
    fclose(f);
    printf("Total bits read: %d.\n" , nobits);

    return 0;
}