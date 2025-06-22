#include <graphics.h>
#include <conio.h>

void drawScene(int carLeft, int carBottom, int stopx, int stopy, int xmax, int ymax) {
    cleardevice();

    // Background
    setbkcolor(WHITE);
    setcolor(GREEN);
    line(0, ymax - 150, xmax, ymax - 150);
    line(0, ymax - 151, xmax, ymax - 151);
    line(0, ymax - 152, xmax, ymax - 152);

    // STOP sign text
    setcolor(RED);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(stopx, stopy, "STOP");

    // STOP board box
    setcolor(BLACK);
    line(stopx - 5, stopy - 5, stopx + 90, stopy - 5);
    line(stopx - 5, stopy - 5, stopx - 5, stopy + 25);
    line(stopx - 5, stopy + 25, stopx + 90, stopy + 25);
    line(stopx + 90, stopy - 5, stopx + 90, stopy + 25);
    line(stopx + 42, stopy + 25, stopx + 42, ymax - 152); // board stand

    // === Mini Car ===
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(carLeft, carBottom - 12, carLeft + 75, carBottom);
    floodfill(carLeft + 1, carBottom - 1, BLUE);

    // Car Top
    rectangle(carLeft + 12, carBottom - 25, carLeft + 62, carBottom - 12);
    floodfill(carLeft + 13, carBottom - 13, BLUE);

    // Wheels
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(carLeft + 12, carBottom + 2, 5);
    floodfill(carLeft + 12, carBottom + 2, BLACK);
    circle(carLeft + 62, carBottom + 2, 5);
    floodfill(carLeft + 62, carBottom + 2, BLACK);

    // Windows
    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    rectangle(carLeft + 15, carBottom - 22, carLeft + 30, carBottom - 14);
    floodfill(carLeft + 16, carBottom - 21, CYAN);
    rectangle(carLeft + 44, carBottom - 22, carLeft + 59, carBottom - 14);
    floodfill(carLeft + 45, carBottom - 21, CYAN);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xmax = getmaxx();
    int ymax = getmaxy();

    int stopx = xmax - 150;
    int stopy = ymax - 200;
    int carBottom = ymax - 155;

    int carLeft = 0;

    while (true) {
        drawScene(carLeft, carBottom, stopx, stopy, xmax, ymax);

        delay(20); // speed of the car

        // Stop when front of car reaches stop sign
        if (carLeft + 75 >= stopx + 40) {
            break;
        }

        carLeft += 2; // speed (pixels per frame)
    }

    getch();
    closegraph();
    return 0;
}




