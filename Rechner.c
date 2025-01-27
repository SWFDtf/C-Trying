#include <stdio.h>
#include <math.h>

int main() {
    //Defining Variables
    unsigned int select;
    const float PI = 3.14159;
    float Area;
    float Umfang;
    float Radius;
    printf("WILLKOMMEN");
    printf("\n");
    printf("(Alles in Kreise)\n");
    printf("Bitte wählen sie eins aus:\n");
    printf("\t 1. Umfang mit Radius\n");
    printf("\t 2. Flächeninhalt mit Radius\n");
    printf("\t 3. Flächeninhalt mit Umfang\n");
    printf("\t 4. Umfang mit Flächeninhalt\n");
    printf("\t 5. Radius mit Flächeninhalt\n");
    printf("\t 6. Radius mit Umfang\n");
    printf("Deine Auswahl: ");
    scanf("%d", &select);
    
    if (select == 1)
    {
        /* code to berechnen the UMfang mit raduzs*/
        printf("\n Radius: ");
        scanf("%f", &Radius);
        printf("\n");
        printf("\n");
        Umfang = 2*PI*Radius;
        printf("Der Umfang beträgt %.3f", Umfang);
    } else if (select == 2)
    {
        
        /* code  Flächeninhalt mit Radius*/

        printf("\n Radius: ");
        scanf("%f", &Radius);
        printf("\n");
        printf("\n");
        Area = PI*Radius*Radius;
        printf("Der Flächeninhalt beträgt %.3f", Area);
    } else if (select == 3)
    {
        /* code Flächeninhalt mit Umfang*/
        printf("\n Umfang: ");
        scanf("%f", &Umfang);
        printf("\n");
        printf("\n");
        Radius = Umfang / (2*PI);
        Area = PI*Radius*Radius;
        printf("Der Flächeninhalt beträgt %.3f", Area);
    } else if (select == 4)
    {
        /* code Umfang mit Flächeninhalt*/

        printf("\n Flächeninhalt: ");
        scanf("%f", &Area);
        printf("\n");
        printf("\n");
        Radius = sqrtf(Area / PI);
        Umfang = 2*PI*Radius;
        printf("Der Umfang beträgt %.3f", Umfang);
    } else if (select == 5)
    {
        /* code Radius mit Flächeninhalt*/
        printf("\n Flächeninhalt: ");
        scanf("%f", &Area);
        printf("\n");
        printf("\n");
        Radius = sqrtf(Area / PI);
        printf("Der Radius beträgt %.3f", Radius);
    } else if (select == 6)
    {
        /* code Radius mit Umfang*/
        printf("\n Umfang: ");
        scanf("%f", &Umfang);
        printf("\n");
        printf("\n");
        Radius = Umfang / (2*PI);
        printf("Der Radius beträgt %.3f", Radius);
    } else
    {
        return 1;
    }
    printf("\n");
    // for outside programms:
    //end
    return 0;
}