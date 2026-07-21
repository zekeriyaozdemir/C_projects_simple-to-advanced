/*
In embedded systems, multiple configuration fields are often packed into a single
register using bit-level operations.

Field       Bits    Position(LSB-first)
MODE        3       Bits 0-2
SPEED       5       Bits 3-7
RESERVED    2       Bits 8-9(must be 0)
STATUS      6       Bits 10-15

Task queue is:
    - Read mode, speed, and status from input.
    - Pack them into a 16-Bit Register.
    - Ensure reserved bits (8-9) remain 0.
    - Print the resulting packed value. 

*/

#include <stdio.h>
#include <stdint.h>

uint16_t PACK_REGISTER(uint8_t MODE, uint8_t SPEED, uint8_t STATUS)
{
    uint16_t REG = 0;
    REG = ((MODE & 0x07) << 0) | 
          ((SPEED & 0x1F) << 3) | 
          ((STATUS & 0x3F) << 10);              //Control with "&" operation, if user give overflowing value.

    if (REG & 0x0300) {printf("Reserved Field is NOT 0!\n");}  //Control, if coder try to giving some value on reserved field.
    
    else {printf("Reserved Field is 0\n");}

    return REG;
}

int main()
{
    uint8_t mode, speed, status;
    scanf("%hhu %hhu %hhu", &mode, & speed, &status);
    printf("STATE OF REGISTER(HEX): 0x%04X\n", PACK_REGISTER(mode, speed, status));

    return 0;
}