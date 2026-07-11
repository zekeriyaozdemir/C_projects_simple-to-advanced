#include <stdio.h>
#include <stdint.h>

uint8_t setPin(uint8_t REG, int POS)        // set bit/pin on POS for "unsigned char uint8_t"
{
    REG |= (1 << POS);
    return REG;
}

int main()
{
    uint8_t reg;
    int pos;
    scanf("%hhu %d", &reg, &pos);
    printf("%u", setPin(reg, pos));

    return 0;
}