/*
Setting only 8-11 bit field on control register.
Do not change other bits.
*/

#include <stdio.h>
#include <stdint.h>

uint32_t SET_BAUD_RATE(uint32_t REG, uint8_t BAUD_VALUE)
{
    REG &= ~(0xF << 8);         //firstly clear 8-11 bit field
    REG |= (BAUD_VALUE << 8);   //and set 8-11 field according to baud rate

    return REG;
}

int main()
{
    uint32_t reg;
    uint8_t baud_value;
    
    scanf("%x %hhu", &reg, &baud_value);

    printf("RESULT : %x", SET_BAUD_RATE(reg, baud_value));

    return 0;
}