#include <stdio.h>
#include <stdint.h>

/*
configured the Register by setting specific bits.
used the Macros
giving a 16-bit control register layout --> ENABLE   : Bit 0
                                            MODE     : Bits 1-2
                                            SPEED    : Bits 3-5
                                            RESERVED : Bits 6-7(must be 0) 
---------------------------------
| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
---------------------------------
|RSV|RSV|SPD|SPD|SPD|MOD|MOD|ENB|
---------------------------------
*/

//Defining mocros
#define PIN_ENABLE(X) (X << 0)
#define PIN_MODE(X) ((X & 0x03) << 1)
#define PIN_SPEED(X) ((X & 0x07) << 3)

uint16_t CONFIG_REG(uint8_t ENABLE, uint8_t MODE, uint8_t SPEED)
{
    uint16_t OUTPUT_REG;
    OUTPUT_REG |= (PIN_ENABLE(ENABLE) | PIN_MODE(MODE) | PIN_SPEED(SPEED));

    return OUTPUT_REG;
}

int main()
{
    uint8_t EN, mode, speed;                        
    scanf("%hhu %hhu %hhu", &EN, &mode, &speed);    
   
    printf("%u", CONFIG_REG(EN, mode, speed));

    return 0;
}
