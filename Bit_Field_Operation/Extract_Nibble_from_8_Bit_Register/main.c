/*
This code will enable to extract high-side bits or low-side bits
on 8-bits register, or up to 32-bits.
*/

#include <stdio.h>
#include <stdint.h>

uint8_t EXTRACT_NIBBLE(uint8_t REG, uint8_t  POS)
{
    if(POS == 0) 
    {
        printf("Lower Nibble --> ");
        return (REG &= 0x0F); 
    }
    else { 
        printf("Upper Nibble --> ");
        return (REG &= 0xF0); 
    }
}

int main()
{
    uint32_t value_REG, value_POS;
    scanf("%hhx %u", &value_REG, & value_POS);
    uint8_t RESULT = EXTRACT_NIBBLE(value_REG, value_POS);
    printf("%hhx", RESULT);


    return 0;
}