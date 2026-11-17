#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void plotCirclePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    int xc, yc, r, x, y, p;

    printf("Enter center (xc yc): ");
    scanf("%d%d", &xc, &yc);
    printf("Enter radius: ");
    scanf("%d", &r);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    x = 0;
    y = r;
    p = 1 - r;

    while (x <= y)
    {
        plotCirclePoints(xc, yc, x, y);
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
    }

    getch();
    closegraph();
    return 0;
}
