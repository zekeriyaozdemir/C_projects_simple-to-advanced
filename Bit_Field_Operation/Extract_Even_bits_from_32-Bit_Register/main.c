/*
From 32-bit register, extract all even-positioned bits (0, 2, 4, ... , 30)
Return the value that extracted.
*/

#include <stdio.h>
#include <stdint.h>

uint32_t EXTRACT_EVEN_BITS(uint32_t REG)
{
    uint32_t shifted_value = 0;
    uint32_t bit_value;

    for(int i = 0; i < 32; i+= 2)
    {
        bit_value = 1 &  (REG >> i);
        shifted_value |= bit_value << (i/2);

    }
    return shifted_value;
}

int main()
{
    uint32_t reg;

    scanf("%X", &reg);
    printf("RESULT : %X", EXTRACT_EVEN_BITS(reg));

    return 0;
}