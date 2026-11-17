#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    line(70, 100, 250, 100);
    circle(400, 150, 65);
    ellipse(650, 150, 0, 360, 100, 55);

    outtextxy(130, 220, "Line");
    outtextxy(365, 240, "Circle");
    outtextxy(610, 240, "Ellipse");

    getch();
    closegraph();
    return 0;
}
