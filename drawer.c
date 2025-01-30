// drawer.c
#include <stdio.h>
#include "drawer.h"

#define WIDTH 80   // Breite des Koordinatensystems
#define HEIGHT 20  // Höhe des Koordinatensystems

// Funktion zur Darstellung der linearen Gleichung y = mx + b
void drawer(double m, double b) {
    char graph[HEIGHT][WIDTH];
    
    // Initialisierung des Koordinatensystems mit Leerzeichen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            graph[i][j] = ' ';
        }
    }

    // Zeichnen der x- und y-Achsen
    for (int i = 0; i < WIDTH; i++) {
        graph[HEIGHT / 2][i] = '-'; // x-Achse
    }
    for (int i = 0; i < HEIGHT; i++) {
        graph[i][WIDTH / 2] = '|'; // y-Achse
    }
    graph[HEIGHT / 2][WIDTH / 2] = '+'; // Ursprung

    // Zeichnen der Geraden y = mx + b
    for (int x = -WIDTH / 2; x < WIDTH / 2; x++) {
        int y = (int)(m * x + b);
        int graph_x = x + WIDTH / 2;
        int graph_y = HEIGHT / 2 - y;

        if (graph_x >= 0 && graph_x < WIDTH && graph_y >= 0 && graph_y < HEIGHT) {
            graph[graph_y][graph_x] = '*';
        }
    }

    // Ausgabe des Koordinatensystems
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(graph[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    double m, b;

    // Eingabe der Parameter der linearen Gleichung
    printf("Geben Sie die Steigung (m) der Geraden ein: ");
    scanf("%lf", &m);
    printf("Geben Sie den y-Achsenabschnitt (b) der Geraden ein: ");
    scanf("%lf", &b);

    // Zeichnen der linearen Gleichung
    drawer(m, b);

    return 0;
}