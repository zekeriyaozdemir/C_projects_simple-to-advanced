#include <stdio.h>
#include <stdint.h>

/*Bit spreading interleave bits with zeros that is used to insert 0s 
between the bits of a value for purposes like data alignment or transmission */

uint16_t SPREAD_INTERLEAVE(uint8_t val)
{
    uint16_t VALUE = 0;

    for(int POS = 0; POS < 8; POS++)
    {
        uint8_t bit = 1 & (val >> POS);     //like a FIFO idea; first bit first out. Checking 1 or 0.
        VALUE |= (bit << (2 * POS));        //And then to place to even positions (0-2-4...).
    }
    return VALUE;
}


int main()
{
    uint8_t value;
    scanf("%u", &value);
    uint16_t result = SPREAD_INTERLEAVE(value);

    printf("RESULT : %u", result);
    return 0;
}

