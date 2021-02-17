#include <stdio.h>


void bin_print(unsigned int i){
    int j = (sizeof(unsigned int)*8);  //num of bits in an integer

    // Temporary value
    int k;
    //loop over the number of bits in i,  left to right
    for(j--; j>=0; j--){
        //Pick out the j^th bit of i 
        k = ((1 << j) & i) ? 1 : 0;
        printf("%d",k);
    }
}

int main(int argc, char *argv[]){
    // i = literal value
    unsigned int i = 0x0f0f0f0f;


    printf("Original:\t");
    //print i in binary
    bin_print(i);

    printf("\t%x\t%u\n\n",i,i);

    //32
    int j = sizeof(unsigned int)*8;
    
    for(j--; j >= 0; j--){

        //1 shifted left j times
        bin_print(1 << j); printf("\n");

        // i
        bin_print(i); printf("\n");
        printf("-------------------------------- &\n");

        // (1 shifted  left j times) bitwise logical and i   
        bin_print((1 << j) & i );  printf("\n\n");
    }


    return 0;
}
