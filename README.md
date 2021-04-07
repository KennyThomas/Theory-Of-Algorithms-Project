# Theory-Of-Algorithms-Project

## Description


## Compilation 


## Explanation


## Answers 

### Q1

<b>Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?</b><br>

When data is passed into the SHA512 algorithm it is computed to a 1024-bit padded message. It is impossible to reverse this hash as it is a
one way algorithm meaning it cannot be reversed. An encryption for example is a two way algorithm as it can be reveresed if the suitable key is used.<br>
This algorithm reads in 128 bytes and computes it to a 1024-bit padded message. Therfore we do not know the original size of the file that was used as input data.<br>
SHA512 uses 1024 bit blocks. Each block uses the result of the previous block to compute the hash. To get the original message would be near impossible has it would mean working back through these block to find the original value. So to retreive the orignal message from the SHA512 hash digest cannot be done.


### Q2

<b>Can you design an algorithm that, given enough time,will find input messages that give each of the possible 512-bit strings?</b>


### Q3

<b>How difficult is it to find a hash digest beginning with at least twelve zeros?</b>
