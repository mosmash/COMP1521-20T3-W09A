// Write a function which reverses the order of the bits in a variable w.
// For example: If w == 0x01234567, the underlying bit string looks like:

// 0000 0001 0010 0011 0100 0101 0110 0111
// which, when reversed, looks like:

// 1110 0110 1010 0010 1100 0100 1000 0000
// which is 0xE6A2C480 in hexadecimal.
#include <stdio.h>
#include <stdlib.h>

/// 1110 
/// 0111
typedef unsigned int Word;

Word reverseBits(Word w) {
    unsigned int result = 0;

    // bit extraction
    // for one bit only, start with 1 and shift to your needed position


    for (int bit = 0; bit < 32; bit++) {
        // // extract our bit
        // unsigned int extracted = w & mask;

        // // set mask to use to set the bit later on 
        // extracted = extracted << (32 - i - 1);

        // // place it in the result.
        // result = result | extracted;

        // mask = mask << 1;

        //
        Word wMask = 1u << (31 - bit);
        Word retMask = 1u << bit;
        if (w & wMask) {
            result = result | retMask;
        }
    }


    return result;
}

int main () {
    int value = 0x01234567;
    reverseBits(value);
    return 0;
}