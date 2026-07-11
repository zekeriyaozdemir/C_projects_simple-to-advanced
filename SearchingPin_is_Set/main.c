#include <stdio.h>

int isSetOrNot(int N, int K)        // check Kth bit/pin; if it is set return 1, o.w. 0.
{
    if ((N & (1 << K)) == 0) return 0;
    else return 1;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", isSetOrNot(n, k));

    return 0;
}