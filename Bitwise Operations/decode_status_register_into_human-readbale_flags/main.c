#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Decodes which flags are sets
// Flags 0 : POWER ON
//       1 : ERROR  
//       2 : TX READY  
//       3 : RX READY  
//       4 : OVERHEAT  
//       5 : UNDERVOLTAGE  
//       6 : TIMEOUT  
//       7 : RESERVED  


void FLAGS_CONTROL(uint8_t REG)
{
    //Array list of Flags
   const char* STATUS_FLAG_NAME[]={
        "POWER ON",
        "ERROR",
        "TX READY",
        "RX READY",
        "OVERHEAT",
        "UNDERVOLTAGE",
        "TIMEOUT",
        "RESERVED"
    };

    //Which flags set
    for(int POS = 0; POS < 8; POS++)
    {
        if(REG & (1 << POS)) 
            printf("%s \n", STATUS_FLAG_NAME[POS]);
    }
}

int main()
{
    uint8_t reg;
    scanf("%d", &reg);
    FLAGS_CONTROL(reg);

    return 0;
}