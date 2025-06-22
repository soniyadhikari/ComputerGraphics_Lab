#include <graphics.h>
#include <stdio.h>
#include <math.h>

void DDA(int x1, int y1, int x2, int y2, int midX, int midY) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(midX + round(x), midY - round(y), WHITE);
        x += xinc;
        y += yinc;
    }
}

int main() {
    int x1, y1, x2, y2;

    // ? Ask for input BEFORE graphics window
    printf("Enter x1 y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter x2 y2: ");
    scanf("%d %d", &x2, &y2);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;

    // Draw X and Y axes
    line(0, midY, getmaxx(), midY); // X-axis
    line(midX, 0, midX, getmaxy()); // Y-axis

    // Draw line using DDA
    DDA(x1, y1, x2, y2, midX, midY);

    getch();
    closegraph();
    return 0;
}


