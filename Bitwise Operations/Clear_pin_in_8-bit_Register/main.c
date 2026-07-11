#include <stdio.h>
#include <stdint.h>

uint8_t clearPin(uint8_t REG, int POS)
{
    REG &= ~(1 << POS);

    return REG;
}

int main()
{
    uint8_t reg;
    int pos;
    scanf("%hhu %d", &reg, &pos);
    printf("%u", clearPin(reg, pos));

    return 0;
}