/*
Given a 32-Bit Register Information. Replace a few bits, starting at position POS
 with a new value. Only the targeted bite must change, others should stay unchanged.
*/

#include <stdio.h>
#include <stdint.h>

uint32_t REPLACE_FIELD(uint32_t REG, uint32_t VALUE, uint8_t POS, uint32_t LEN)
{
    for(int i = 0; i < LEN; i++)
    {
        uint32_t bit = 1 & (VALUE >> i);
        if(bit != 0)
        {
            REG |= (1 << (POS + i)); 
        }
        else{
            REG &= ~(1 << (POS + i)); 
        }
    }
    return REG;
}

int main()
{
    uint32_t reg, val;
    uint8_t pos, len;

    scanf("%x %x %hhu %hhu", &reg, &val, &pos, &len);

    uint32_t RESULT = REPLACE_FIELD(reg, val, pos, len);

    printf("RESULT : %X\n", RESULT);

    return 0;
}