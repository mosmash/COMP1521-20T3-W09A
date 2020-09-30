// Write a C function, six_middle_bits, which, given a uint32_t, extracts and returns the middle six bits.

#include <stdio.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t u) {

}

int main () {
    uint32_t number = 42;
    // 0000 0000 0000 0XXX XXX0 0000 0000 0000 ->
    // to extract:
        // create a mask
        // use &
    uint32_t mask = 0x0000003F;
    // 0000 0000 0000 0000 0000 0000 0011 1111
    // number & mask ???
    uint32_t result = (number >> 13) & mask;

    return 0;
}