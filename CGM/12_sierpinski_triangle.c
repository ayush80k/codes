#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void sierpinski(int x1, int y1, int x2, int y2,
                int x3, int y3, int level)
{
    int x12, y12, x23, y23, x31, y31;

    if (level == 0)
    {
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
        return;
    }

    x12 = (x1 + x2) / 2;
    y12 = (y1 + y2) / 2;
    x23 = (x2 + x3) / 2;
    y23 = (y2 + y3) / 2;
    x31 = (x3 + x1) / 2;
    y31 = (y3 + y1) / 2;

    sierpinski(x1, y1, x12, y12, x31, y31, level - 1);
    sierpinski(x12, y12, x2, y2, x23, y23, level - 1);
    sierpinski(x31, y31, x23, y23, x3, y3, level - 1);
}

int main()
{
    int gd = DETECT, gm, level;

    printf("Enter recursion level (0-7): ");
    scanf("%d", &level);

    if (level < 0 || level > 7)
    {
        printf("Enter a level between 0 and 7.");
        getch();
        return 0;
    }

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setcolor(WHITE);
    sierpinski(320, 30, 50, 420, 590, 420, level);

    getch();
    closegraph();
    return 0;
}
