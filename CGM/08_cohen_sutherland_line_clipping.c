#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int getCode(float x, float y, int xmin, int ymin, int xmax, int ymax)
{
    int code = 0;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

int main()
{
    int gd = DETECT, gm;
    int xmin, ymin, xmax, ymax, c1, c2, accept = 0, code;
    float x1, y1, x2, y2, x, y;

    printf("Enter clipping window xmin ymin xmax ymax: ");
    scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
    printf("Enter line endpoints x1 y1 x2 y2: ");
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(RED);
    line((int)x1, (int)y1, (int)x2, (int)y2);

    c1 = getCode(x1, y1, xmin, ymin, xmax, ymax);
    c2 = getCode(x2, y2, xmin, ymin, xmax, ymax);

    while (1)
    {
        if (!(c1 | c2))
        {
            accept = 1;
            break;
        }
        else if (c1 & c2)
            break;
        else
        {
            code = c1 ? c1 : c2;
            if (code & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (code & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (code & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code == c1)
            {
                x1 = x; y1 = y;
                c1 = getCode(x1, y1, xmin, ymin, xmax, ymax);
            }
            else
            {
                x2 = x; y2 = y;
                c2 = getCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept)
    {
        setcolor(GREEN);
        line((int)x1, (int)y1, (int)x2, (int)y2);
        outtextxy(10, 10, "Accepted and clipped line");
    }
    else
        outtextxy(10, 10, "Line rejected");

    getch();
    closegraph();
    return 0;
}
