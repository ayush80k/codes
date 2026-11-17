#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void drawTriangle(float p[3][2], int color)
{
    int i;
    setcolor(color);
    for (i = 0; i < 3; i++)
        line((int)p[i][0], (int)p[i][1],
             (int)p[(i + 1) % 3][0], (int)p[(i + 1) % 3][1]);
}

int main()
{
    int gd = DETECT, gm, choice, i;
    float p[3][2], q[3][2], a, b, angle, rad, shx, shy;
    float cx, cy, temp;

    printf("Enter three vertices (x y):\n");
    for (i = 0; i < 3; i++)
        scanf("%f%f", &p[i][0], &p[i][1]);

    printf("\n2D Transformations\n");
    printf("1. Translation\n2. Rotation\n3. Scaling\n");
    printf("4. Reflection\n5. Shearing\nEnter choice: ");
    scanf("%d", &choice);

    for (i = 0; i < 3; i++)
    {
        q[i][0] = p[i][0];
        q[i][1] = p[i][1];
    }

    if (choice == 1)
    {
        printf("Enter tx ty: ");
        scanf("%f%f", &a, &b);
        for (i = 0; i < 3; i++)
        {
            q[i][0] += a;
            q[i][1] += b;
        }
    }
    else if (choice == 2)
    {
        printf("Enter angle in degrees: ");
        scanf("%f", &angle);
        rad = angle * PI / 180.0;
        for (i = 0; i < 3; i++)
        {
            temp = q[i][0];
            q[i][0] = temp * cos(rad) - q[i][1] * sin(rad);
            q[i][1] = temp * sin(rad) + q[i][1] * cos(rad);
        }
    }
    else if (choice == 3)
    {
        printf("Enter sx sy: ");
        scanf("%f%f", &a, &b);
        for (i = 0; i < 3; i++)
        {
            q[i][0] *= a;
            q[i][1] *= b;
        }
    }
    else if (choice == 4)
    {
        printf("Reflection: 1-X axis  2-Y axis  3-Origin  4-Y=X: ");
        scanf("%d", &choice);
        for (i = 0; i < 3; i++)
        {
            if (choice == 1) q[i][1] = -q[i][1];
            else if (choice == 2) q[i][0] = -q[i][0];
            else if (choice == 3) { q[i][0] = -q[i][0]; q[i][1] = -q[i][1]; }
            else if (choice == 4) { temp = q[i][0]; q[i][0] = q[i][1]; q[i][1] = temp; }
        }
    }
    else if (choice == 5)
    {
        printf("Enter shx shy: ");
        scanf("%f%f", &shx, &shy);
        for (i = 0; i < 3; i++)
        {
            temp = q[i][0];
            q[i][0] = temp + shx * q[i][1];
            q[i][1] = q[i][1] + shy * temp;
        }
    }
    else
    {
        printf("Invalid choice.");
        getch();
        return 0;
    }

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setcolor(YELLOW);
    line(0, 240, 639, 240);
    line(320, 0, 320, 479);

    for (i = 0; i < 3; i++)
    {
        p[i][0] += 320;
        p[i][1] = 240 - p[i][1];
        q[i][0] += 320;
        q[i][1] = 240 - q[i][1];
    }
    drawTriangle(p, WHITE);
    drawTriangle(q, LIGHTGREEN);
    outtextxy(10, 10, "Original: White   Transformed: Green");

    getch();
    closegraph();
    return 0;
}
