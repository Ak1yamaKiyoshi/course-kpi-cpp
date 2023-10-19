#include <stdio.h>

int main() {
    short c;

    printf(" Enter celsius: "); 
    scanf("%d", &c);

    for (short i = 0; i < c; i++) 
    printf(" %dC = %dF\n", i, (short)(9/5*i + 32));
}