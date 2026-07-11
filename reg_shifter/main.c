#include <stdio.h>

unsigned char modifyBit(unsigned char reg, int pos, int mode)
{
    if(mode==1) // mode for SET
    {
        reg |= (1 << pos);
    }
    else {
        reg &= ~(1 << pos);
    }
}

int main()
{
    unsigned char reg;
    int pos, mode;
    scanf("%hhu %d %d", &reg, &pos, &mode);
    printf("%d", modifyBit(reg, pos, mode));

    return 0;
}