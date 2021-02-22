#include <stdio.h>
#include <inttypes.h>
#define WORD uint32_t
#define PF PRIX32



WORD Ch(WORD x , WORD y, WORD z){
    return (x & y)^(~ x & z);

}


WORD Maj(WORD x , WORD y, WORD z){
    return (x & y) ^ (x & z) ^ (x & z);

}





int main(int argc, char *argv[]){

    WORD x = 0x0F0F0F0F;
    WORD y = 0x0A0a0A0A;
    WORD z = 0xB0B0B0B0;
    
    WORD ch = Ch(x,y,z);
    WORD maj = Ch(x,y,z);

    printf("Ch(%08" PF  ",%08"  PF  ",%08" PF ") = %08" PF "\n",x, y, z, ch);
    printf("Maj(%08" PF  ",%08"  PF  ",%08" PF ") = %08" PF "\n",x, y, z, maj);

    return 0;
}