#include <stdio.h>
#include <stdint.h>

uint32_t setPin(uint32_t REG, uint8_t POS, uint8_t LEN)
{
    for(int i = 0; i < LEN; i++)
    {
        REG |= (1 << POS);
        POS++;
    }
    return REG;
}

int main()
{
    uint32_t reg;
    uint8_t pos, len;
    scanf("%u %hhu %hhu", &reg, &pos, &len);
    uint32_t RESULT = setPin(reg, pos, len);

    printf("%lu", RESULT);

    return 0;
}