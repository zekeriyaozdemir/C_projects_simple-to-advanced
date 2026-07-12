#include <stdio.h>
#include <stdint.h>

uint16_t highestPin(uint16_t REG)
{

    uint16_t hideREG;
    for(int pos = 0; pos < 16; pos++)
    {
        hideREG = REG;
        REG &= ~(1 << pos);
        if(REG == 0) return hideREG;
    }

}

int main()
{
    uint16_t reg;
    scanf("%u", &reg);
    uint16_t stackREG = highestPin(reg);
    
    printf("%u", stackREG);
    
    return 0;
}