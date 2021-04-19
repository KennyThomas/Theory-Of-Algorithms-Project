#!/bin/bash


#Test 1
echo "Running Test on input.txt."
myout="$(./sha512 input.txt)  input.txt"
expec="$(sha512sum input.txt)"
echo "Expected:  "$expec
echo "Output is: "$myout
if [[ $expec == $myout ]]; then
    echo "Pass"
    num=$(( $num + 1 ))
else
    echo "Fail"
fi

#Test 2
echo "Running Test on TestFile.txt."
myout="$(./sha512 TestFile.txt)  TestFile.txt"
expec="$(sha512sum TestFile.txt)"
echo "Expected:  "$expec
echo "Output is: "$myout
if [[ $expec == $myout ]]; then
    echo "Pass"
    num=$(( $num + 1 ))

else
    echo "Fail"
fi

if [[ $num == 2 ]]; then
    echo "All tests passed 2/2"
    

else
    echo "Fail"
fi


