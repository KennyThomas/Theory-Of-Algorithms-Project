#include <stdio.h>
#include <inttypes.h>
#define WORD uint32_t
#define PF PRIX32

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

WORD Ch(WORD x , WORD y, WORD z){
    return (x & y)^(~ x & z);

}


WORD Maj(WORD x , WORD y, WORD z){
    return (x & y) ^ (x & z) ^ (x & z);

}

WORD ROTR(WORD x, int n){
   return (x)=(x>>n) | (x<<x*16-n);

}




int main(int argc, char *argv[]){

    WORD x = 0x0F0F0F0F;
    WORD y = 0x0A0a0A0A;
    WORD z = 0xB0B0B0B0;
    
    WORD ch = Ch(x,y,z);
    WORD maj = Ch(x,y,z);
    WORD rotr = ROTR(x,2);

    printf("Ch(%08" PF  ",%08"  PF  ",%08" PF ") = %08" PF "\n",x, y, z, ch);
    printf("Maj(%08" PF  ",%08"  PF  ",%08" PF ") = %08" PF "\n",x, y, z, maj);
    printf("ROTR(%08" PF " = %08" PF "\n",y, rotr);
    return 0;
}