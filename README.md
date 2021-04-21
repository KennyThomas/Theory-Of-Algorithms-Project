# Theory-Of-Algorithms-Project

## Description
This repository contains the code to compute the SHA512 alogorithm on a txt file.<br>
The code can be found in the file called sha512.c<br>
There is also a Make file that is used to use command line arguements such as
* "make sha512" - This runs the algorithm on the txt file input.txt
* "make test" - This runs tests to see if the algorithm is producding the right hash.
* "make clean" - This removes the executable file sha512, this is done so the user can rerun the project


## Compilation 
* Clone repository
* Open project in Debian or Ubuntu
#### Run main code
* Run command "make Sha5122
* This will run the code and display the output.
* You can change the the message is by editing input.txt.

#### Run tests
* Run command "make test"
* This will display if the tests passed or not
* If all tests pass a message will display

#### To run main code again
* Run command "make clean"
* This will remove the executable file
* Run command "make Sha512"



## Explanation
The SHA512 is one of many hash algorithms apart of the the SHA-2 group including alogorithms such as SHA256 and SHA224. <br>
The SHA512 is an algorithm that takes in some data, in this case a .txt file containing a word or sentence.
Firstly the algorithm goes through a step called preprocessing.
#### Preprocessing
In this step we set the inital values of H.
```C
 //5.3.5 
    WORD H[]={  0x6a09e667f3bcc908 , 0xbb67ae8584caa73b , 0x3c6ef372fe94f82b , 0xa54ff53a5f1d36f1, 
                0x510e527fade682d1, 0x9b05688c2b3e6c1f , 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
        };
```
Once the inital values are set we can the read in the file , if the file is successfully read in we can then perform padding on the message.
#### Padding the message
The reason we pad the message is to ensure the message is a multiple of 1024 bits. We use a multiple of 1024 because the SHA512 uses blocks of 1024 bits.<br>
The block is shown below
```C
 union Block{
    BYTE bytes[128];    // 8  * 128 = 1024
    WORD words[16];    //  16 * 64  = 1024
    uint64_t sixf[16];//   16 * 64  = 1024
};
```
For padding the message to get the desired length we append "0" bits with a leading "1" until the message is a multiple of 128. 
```C
if(nobytes == 128){      
            
            return 1;
        } else if(nobytes < 112){
            M->bytes[nobytes] = 0x80; // in bits: 10000000

            for(nobytes++; nobytes < 128;nobytes++){
                M->bytes[nobytes] = 0x00; // in bits: 00000000
            }

            // Append length of original input
            M->sixf[15] = (is_lilendian() ? bswap_64(*nobits)  : *nobits);
            //say this is the last block
            *S = END;
```
The code above shows if we cant read in 128 bits then append bits to the original length.

The final step is to perform hash computation.

#### Hash Computation
This step requires the hash to go through a series of math computations N times to get a 512 message digest.
The math computations are shown below
```C
//Section 6.4.2 part 1
    for(t = 0; t < 16; t++)
        W[t] = M->words[t];
    for (t = 16; t < 80; t++ )
        W[t] = Sig1(W[t-2]) + W[t-7] + Sig0(W[t-15]) + W[t-16];



    //Section 6.4.2 part 2

    a = H[0]; 
    b = H[1]; 
    c = H[2]; 
    d = H[3]; 
    e = H[4]; 
    f = H[5]; 
    g = H[6]; 
    h = H[7];

    //Section 6.4.2 part 3
    for(t=0; t < 80; t++){
        T1 = h + SIG1(e) + CH(e,f,g) + K[t] + W[t];
        T2 = SIG0(a) + MAJ(a,b,c);
        h = g; 
        g = f; 
        f = e; 
        e = d + T1; 
        d = c; c = b; 
        b = a; 
        a = T1 + T2;
    }

    //Section 6.4.2 part 4

    H[0] = a + H[0]; 
    H[1] = b + H[1]; 
    H[2] = c + H[2]; 
    H[3] = d + H[3]; 
    H[4] = e + H[4]; 
    H[5] = f + H[5]; 
    H[6] = g + H[6]; 
    H[7] = h + H[7];
    return 0;
}
```
Once this is finished we are left with our hash message. <br>
For example "abc" put through the SHA512 algorithm would compute to be ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f


## Answers 

### Q1

<b>Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?</b><br>

When data is passed into the SHA512 algorithm it is computed to a 1024-bit padded message. It is impossible to reverse this hash as it is a
one way algorithm meaning it cannot be reversed. An encryption for example is a two way algorithm as it can be reveresed if the suitable key is used.<br>
This algorithm reads in 128 bytes and computes it to a 1024-bit padded message. Therfore we do not know the original size of the file that was used as input data.<br>
SHA512 uses 1024 bit blocks. Each block uses the result of the previous block to compute the hash. To get the original message would be near impossible has it would mean working back through these block to find the original value. So to retreive the orignal message from the SHA512 hash digest cannot be done.


### Q2

<b>Can you design an algorithm that, given enough time,will find input messages that give each of the possible 512-bit strings?</b>

The SHA-512 produces 512 bits so there would be 2⁵¹² possible outputs which works out to be 1.340780793e+154 combinations. Doing research into how a hash algorithm could be broken I found the Pigeonhole Principle and the Birthday Paradox to be promising. The Birthday Paradox states that if 366 people attend a birthday there would be a 100% chance there would be a shared birthday as there are only 366 days in a year containing February 29th which is a leap year. So if we applied this paradox to the SHA-512 algorithm it would be possible to design an algorithm that will find each of the possible 512- bit strings. This is also known as a Birthday attack.
The Pigeonhole Principle states that if 20 pigeons are put into 19 boxes, one of these boxes will contain two. Bringing this into the SHA512 if we compute more combinations we would find each of the possible 512-bit strings. 

### Q3

<b>How difficult is it to find a hash digest beginning with at least twelve zeros?</b>



