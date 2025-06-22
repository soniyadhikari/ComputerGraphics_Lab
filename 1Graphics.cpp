#include<graphics.h>
#include<stdio.h>
int main(){
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
	putpixel(5, 5, WHITE);
	line(20, 20, 20, 40);
	line(50, 50, 50, 100);
	line(50, 100, 80, 50);
	line(80, 50, 50, 50);
	outtext("Hello, My name is Soniya.");
	line(200, 200, 200, 400);
	line(600, 200, 600, 400);
	line(200, 200, 600, 200);
	line(200, 400, 600, 400);
	circle(60, 150, 30);
	getch();
    closegraph();
   return 0;
}
