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
        // "mask" for checking the bit stored in w.
        // this goes from left -> right
        Word wMask = 1u << (31 - bit); 
        // "mask" to set the bit in result
        // this goes from right -> left and will always be in the opposite position to wMask
        Word retMask = 1u << bit;

        // check if w has a bit set (ie, the bit is 1) at the current position (determined by wMask)
        if (w & wMask) {
            // if it was set then set the current bit of result to 1.
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