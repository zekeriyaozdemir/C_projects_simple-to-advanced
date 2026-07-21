/*
Check the 10-14 bits in 32-bit register.
If 10-14 bits is less than 31(1F), add 1 to in range bits field(10-14).
If it is equal or higher, not change 10-14 bits. 
*/

#include <stdio.h>
#include <stdint.h>

uint32_t EXTRACT_MODIFY(uint32_t REG)
{   
    
    //checking 10-14 bits field less or higher than 31.
    if(((REG >> 10) & 0x1F) < 0x1F)
    {
        REG |= (((REG >> 10) & 0x1F) + 1) << 10;  
    }
    
    return REG;
}

int main()
{
    uint32_t reg;
    scanf("%x", &reg);
    printf("%08x", EXTRACT_MODIFY(reg));

    return 0;
}