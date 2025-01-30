#include <stdio.h>
#include <math.h>

// Definition der quadratischen Funktion ax^2 + bx + c
double quadratic_function(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

// Funktion zur Suche der Nullstelle
double find_root(double a, double b, double c, double start, double end, double precision) {
    double mid;
    while ((end - start) > precision) {
        mid = (start + end) / 2;
        if (quadratic_function(a, b, c, mid) == 0.0) {
            return mid;
        } else if (quadratic_function(a, b, c, start) * quadratic_function(a, b, c, mid) < 0) {
            end = mid;
        } else {
            start = mid;
        }
    }
    return mid;
}

int main() {
    double a, b, c;
    double start, end;
    double root;
    
    // Eingabe der Koeffizienten der quadratischen Funktion
    printf("Geben Sie die Koeffizienten der quadratischen Funktion (a b c) ein: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    // Eingabe des Suchbereichs
    printf("Geben Sie den Start- und Endwert des Suchbereichs ein: ");
    scanf("%lf %lf", &start, &end);
    
    // Suche der Nullstelle mit abnehmender Schrittweite
    root = find_root(a, b, c, start, end, 100); // Hunderterschritte
    root = find_root(a, b, c, root - 100, root + 100, 10); // Zehnerschritte
    root = find_root(a, b, c, root - 10, root + 10, 1); // Einerschritte
    root = find_root(a, b, c, root - 1, root + 1, 0.1); // Zehntelschritte
    root = find_root(a, b, c, root - 0.1, root + 0.1, 0.01); // Hundertstelschritte
    root = find_root(a, b, c, root - 0.01, root + 0.01, 0.001); // Tausendstelschritte

    printf("Die Nullstelle der Funktion ist x = %.6f\n", root);
    
    return 0;
}
