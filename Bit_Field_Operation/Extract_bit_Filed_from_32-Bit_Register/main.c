/*
Working on 32-bit Hardware Status Register (REG). Extract a few bits from it,
strating from a given bit position (POS) and covering a given length (LEN).
Return the extracted value as an unsigned integer.
*/

#include <stdio.h>
#include <stdint.h>

uint32_t EXTRACT_BIT_FIELD(uint32_t REG, uint8_t POS, uint8_t LEN)
{
    if(POS == 0 && LEN == 32)
    {
        return REG;
    }

    else
    {
        REG = REG >> POS;
        uint32_t MASK_BITS = 0;

        for(int i = LEN; i < 32; i++)
        {
            MASK_BITS |= (1 << i);
        }

        REG &= ~MASK_BITS;  
        return REG;
    }
}

int main()
{
    uint32_t RESULT, reg;
    uint8_t pos, len;

    scanf("%x %hhu %hhu", &reg, &pos, &len);

    RESULT = EXTRACT_BIT_FIELD(reg, pos, len);

    printf("RESULT : %x", RESULT);

    return 0;
}