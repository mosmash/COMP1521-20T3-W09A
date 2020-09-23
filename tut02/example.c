// 
#include <stdint.h> // 


int = 32 or 16 bits

int8_t signed_number = // can have negatives -128 ... 127
16
32
64

// unsigned 
uint8_t unsigned_number = // 0 ... 255

printf("%x for hex, %o for octal")

'0' or '1'


char *array = {'0', '1', '0', '1', '1', '\0'};

int16_t result = 0; // 0000 0000 (binary)

result = result | (1u << 4); 
// 1110 1011
// 0000 0001 << 4
// 0001 0000
// 1111 1011

print("%d", result);