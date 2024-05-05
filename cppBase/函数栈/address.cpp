#include <stdio.h>

int sum(int x, int y)
{
    int accum = 1;
    accum = accum + x + y;
    return accum;
}

int main(int argc, char **argv)
{
    int x = 1, y = 2;
    int result = sum(x, y);
    printf("result = %d", result);
    return 0;
}