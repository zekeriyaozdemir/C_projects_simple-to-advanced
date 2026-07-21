/*
Preparing a 32-bit value to send over a communication bus.
To ensure compatibility across platforms, must convert the value into 4 bytes (big-endian order)
Store them in a byte array.
Big-Endian-Order : Store the MSB on lowest position like address.
*/

#include <stdio.h>
#include <stdint.h>

void convert_to_big_endian(uint32_t REG, uint8_t array_store[])
{
    for(int i = 3; i >= 0; i--)
    {
        array_store[i] = (REG >> (24 - (8 * i))) & 0xFF;        //Because of the 32-bit register, the value shifted 8-bit to 8-bit
    }
}

int main()
{
    uint32_t value;
    uint8_t arr[4];
    scanf("%x", &value);
    convert_to_big_endian(value, arr);
    for(int i = 0; i < 4; i++)
    {
        printf("array_store[%d] : %x\n", i, arr[i]);
    }


    return 0;
}