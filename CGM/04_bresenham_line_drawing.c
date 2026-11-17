#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, dx, dy, sx, sy, err, e2;

    printf("Enter x1 y1: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter x2 y2: ");
    scanf("%d%d", &x2, &y2);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    sx = (x1 < x2) ? 1 : -1;
    sy = (y1 < y2) ? 1 : -1;
    err = dx - dy;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    while (1)
    {
        putpixel(x1, y1, WHITE);
        if (x1 == x2 && y1 == y2)
            break;

        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }

    getch();
    closegraph();
    return 0;
}
