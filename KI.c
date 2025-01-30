#include <stdio.h>

int main() {
    const double KohlenhydrateLimit = 35.6;
    const double ZuckerLimit = 14;
    const double EiweissLimit = 10;
    double Kohlen;
    double Zucker;
    double Eiweiss;
    printf("\nGib die Kohlenhyrate, den Zucker und den Eiweiß an: (a b c)\n");
    scanf("%lf", &Kohlen);
    scanf("%lf", &Zucker);
    scanf("%lf",&Eiweiss);
    if (Kohlen < KohlenhydrateLimit || Kohlen == KohlenhydrateLimit) {
        if (Zucker < ZuckerLimit || Zucker == ZuckerLimit) {
            printf("\nEher gut\n");
        } else {
            printf("\nEher schlecht\n");
        }
    } else {
        if (Eiweiss > EiweissLimit) {
            printf("\nEher schlecht\n");
        } else {
            printf("\nEher gut\n");
        }
    }
    return 0;
    




}
