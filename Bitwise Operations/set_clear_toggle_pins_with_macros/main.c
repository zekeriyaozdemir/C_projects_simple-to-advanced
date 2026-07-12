#include <stdio.h>
#include <stdint.h>

#define SET_PIN(REG, POS)     (REG |= (1 << POS))
#define TOGGLE_PIN(REG, POS)  (REG ^= (1 << POS))   
#define CLEAR_PIN(REG, POS)   (REG &= ~(1 << POS))

int main()
{
    // Set bits/pins 2 and 7, Clear bit/pin 3, Toggle bit/pin 5.
    // Do it in order. (SET, CLEAR, TOGGLE)

    uint8_t reg;
    scanf("%u", &reg);
    SET_PIN(reg, 2);
    SET_PIN(reg, 7);
    CLEAR_PIN(reg, 3);
    TOGGLE_PIN(reg, 5);

    printf("%u", reg);
    return 0;
}