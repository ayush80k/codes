#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    int x, y, color;

    printf("Enter x-coordinate (0-639): ");
    scanf("%d", &x);
    printf("Enter y-coordinate (0-479): ");
    scanf("%d", &y);
    printf("Enter color (1-15): ");
    scanf("%d", &color);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    putpixel(x, y, color);
    outtextxy(10, 10, "Pixel plotted at the entered coordinate");

    getch();
    closegraph();
    return 0;
}
