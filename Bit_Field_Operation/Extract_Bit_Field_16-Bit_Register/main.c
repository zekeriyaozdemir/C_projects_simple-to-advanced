/*
Extract 4-8 bit field and return as an unsigned integer.
*/

#include <stdio.h>
#include <stdint.h>

uint8_t EXTRACT_BIT_FIELD(uint16_t REG)
{
    REG &= 0x01F0;
    REG = (REG >> 4);
    return REG;
}

int main()
{
    uint16_t reg;
    scanf("%x", &reg);
    printf("%hhu", EXTRACT_BIT_FIELD(reg));

    return 0;
}