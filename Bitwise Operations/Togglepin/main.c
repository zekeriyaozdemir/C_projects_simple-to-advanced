#include <stdio.h>

int TogglePin(int N)    // toggle 5th pin/bit on N
{
    N ^= (1 << 5);
    return N;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", TogglePin(n));

    return 0;
}