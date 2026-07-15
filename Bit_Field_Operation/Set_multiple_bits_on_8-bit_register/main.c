/*
Set all bits between position start and end (inclusive) on 8-Bit register.
Use 0-based indexing and assume start <= end.
*/

#include <stdio.h>
#include <stdint.h>

uint8_t SET_MULTIPLE_PIN(uint8_t REG, int START_PIN, int STOP_PIN)
{
    
    while(START_PIN <= STOP_PIN)
    {
        REG |= (1 << START_PIN);
        START_PIN++;   
    }
    return REG;
}

int main()
{
    uint8_t value_REG;
    int start_pin, stop_pin;

    scanf("%u %d %d", &value_REG, &start_pin, & stop_pin);

    printf("%hhu", SET_MULTIPLE_PIN(value_REG, start_pin, stop_pin));

    return 0;
}