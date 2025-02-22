#include <stdio.h>

int main(){   
    unsigned char x;
    int n;

    printf("Enter an 8-bit number: ");
    scanf("%d", &n);
    x = (unsigned char)n;
    int numbits = 
    0;
    int x1 = x;
    numbits += (x1 & 1);
    x1 >>= 1;
    numbits += (x1 & 1);
    x1 >>= 1;
    numbits += (x1 & 1);
    x1 >>= 1;
    numbits += (x1 & 1);
    x1 >>= 1;
    numbits += (x1 & 1);
    x1 >>= 1;
    numbits += (x1 & 1);
    x1 >>= 1;
    numbits += (x1 & 1);
    x1 >>= 1;
    numbits += (x1 & 1);
    

    printf("The number %d has %d non-zero bits\n", x, numbits);
    return 0;
}