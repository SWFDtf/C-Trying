#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c;
    printf("\nGib die Längen a und b eines Rechtwinkliges Dreieck ein:\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("\nb: ");
    scanf("%lf",b);
    c = sqrt(a+b);
    printf("\n\n c: %lf", c);
    return 0;
}