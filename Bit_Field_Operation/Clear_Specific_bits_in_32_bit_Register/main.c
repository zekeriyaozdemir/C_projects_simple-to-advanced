/*
Given 32-Bit Register, Clear bits as group of LEN length. Starting from POS position giving by user
*/

#include <stdio.h>
#include <stdint.h>

uint32_t CLEAR_GROUP_PINS(uint32_t REG, uint8_t POS, uint8_t LEN)
{
    for(int i = 0; i < LEN; i++)
    {
        REG &= ~(1 << POS);
        POS++;
    }

    return REG;
}

int main()
{
    uint32_t reg;
    uint8_t pos, len;

    scanf("%x %hhu %hhu", &reg, &pos, &len);

    uint32_t RESULT = CLEAR_GROUP_PINS(reg, pos, len);

    printf("RESULT : %x", RESULT);

    return 0;
}