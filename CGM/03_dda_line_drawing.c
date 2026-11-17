#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, steps, i;
    float dx, dy, xInc, yInc, x, y;

    printf("Enter x1 y1: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter x2 y2: ");
    scanf("%d%d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;
    steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
    x = x1;
    y = y1;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    if (steps == 0)
        putpixel(x1, y1, WHITE);
    else
    {
        xInc = dx / steps;
        yInc = dy / steps;
        for (i = 0; i <= steps; i++)
        {
            putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
            x += xInc;
            y += yInc;
        }
    }

    getch();
    closegraph();
    return 0;
}
