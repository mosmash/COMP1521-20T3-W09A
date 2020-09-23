#define READING   0x01 //= 0b0000 0001
#define WRITING   0x02 //= 0b0000 0010
#define AS_BYTES  0x04 //= 0b0000 0100
#define AS_BLOCKS 0x08 //= 0b0000 1000
#define LOCKED    0x10 //= 0b0001 0000

int main () {
    unsigned char device;
    // mark the device as locked for reading bytes
    device = 0; // 0000 0000
    device = device | READING; // 0000 0001
    device = device | LOCKED;  // 0001 0001

    // mark the device as locked for writing bytes
    device = 0; // 0000 0000
    device = device | WRITING; // 0000 0010
    device = device | LOCKED;  // 0001 0010

    // mark the device as locked without changing any other bytes
    // -> use or! "|"
    device = device | LOCKED;
    device |= LOCKED; // does the same as the above line.

    // remove the lock on a device, leaving other flags unchanged
    device = device & ~LOCKED;
    //   0001 0010 & 
    //   1110 1111 
    //   0000 0010

    //      ^  &~
    // 0 0  0  0
    // 0 1  1  0
    // 1 0  1  1
    // 1 1  0  0

    // toggle between reading and writing, leaving other flags unchanged
    device ^= READING;
    device ^= WRITING;
    
}