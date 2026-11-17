#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void plotEllipsePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    int xc, yc, rx, ry, x, y;
    float dx, dy, d1, d2, rx2, ry2;

    printf("Enter center (xc yc): ");
    scanf("%d%d", &xc, &yc);
    printf("Enter x-radius and y-radius: ");
    scanf("%d%d", &rx, &ry);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rx2 = rx * rx;
    ry2 = ry * ry;
    x = 0;
    y = ry;
    dx = 2 * ry2 * x;
    dy = 2 * rx2 * y;
    d1 = ry2 - rx2 * ry + 0.25 * rx2;

    while (dx < dy)
    {
        plotEllipsePoints(xc, yc, x, y);
        if (d1 < 0)
        {
            x++;
            dx = dx + 2 * ry2;
            d1 = d1 + dx + ry2;
        }
        else
        {
            x++;
            y--;
            dx = dx + 2 * ry2;
            dy = dy - 2 * rx2;
            d1 = d1 + dx - dy + ry2;
        }
    }

    d2 = ry2 * (x + 0.5) * (x + 0.5)
       + rx2 * (y - 1) * (y - 1) - rx2 * ry2;

    while (y >= 0)
    {
        plotEllipsePoints(xc, yc, x, y);
        if (d2 > 0)
        {
            y--;
            dy = dy - 2 * rx2;
            d2 = d2 + rx2 - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + 2 * ry2;
            dy = dy - 2 * rx2;
            d2 = d2 + dx - dy + rx2;
        }
    }

    getch();
    closegraph();
    return 0;
}
