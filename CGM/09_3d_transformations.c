#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void project(float p[8][3], int color)
{
    int i, x[8], y[8];
    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    for (i = 0; i < 8; i++)
    {
        x[i] = 320 + (int)(p[i][0] + 0.5 * p[i][2]);
        y[i] = 240 - (int)(p[i][1] + 0.35 * p[i][2]);
    }
    setcolor(color);
    for (i = 0; i < 12; i++)
        line(x[edges[i][0]], y[edges[i][0]],
             x[edges[i][1]], y[edges[i][1]]);
}

int main()
{
    int gd = DETECT, gm, choice, i, axis;
    float p[8][3], q[8][3], a, b, c, angle, rad, t;

    {
        float base[8][3] = {
            {-60,-60,-60},{60,-60,-60},{60,60,-60},{-60,60,-60},
            {-60,-60,60},{60,-60,60},{60,60,60},{-60,60,60}
        };
        for (i = 0; i < 8; i++)
        {
            p[i][0] = base[i][0];
            p[i][1] = base[i][1];
            p[i][2] = base[i][2];
        }
    }

    printf("3D Transformations\n1. Translation\n2. Rotation\n3. Scaling\nEnter choice: ");
    scanf("%d", &choice);

    for (i = 0; i < 8; i++)
    {
        q[i][0] = p[i][0];
        q[i][1] = p[i][1];
        q[i][2] = p[i][2];
    }

    if (choice == 1)
    {
        printf("Enter tx ty tz: ");
        scanf("%f%f%f", &a, &b, &c);
        for (i = 0; i < 8; i++)
        {
            q[i][0] += a; q[i][1] += b; q[i][2] += c;
        }
    }
    else if (choice == 2)
    {
        printf("Enter axis (1-X 2-Y 3-Z) and angle: ");
        scanf("%d%f", &axis, &angle);
        rad = angle * PI / 180.0;
        for (i = 0; i < 8; i++)
        {
            if (axis == 1)
            {
                t = q[i][1];
                q[i][1] = t * cos(rad) - q[i][2] * sin(rad);
                q[i][2] = t * sin(rad) + q[i][2] * cos(rad);
            }
            else if (axis == 2)
            {
                t = q[i][0];
                q[i][0] = t * cos(rad) + q[i][2] * sin(rad);
                q[i][2] = -t * sin(rad) + q[i][2] * cos(rad);
            }
            else if (axis == 3)
            {
                t = q[i][0];
                q[i][0] = t * cos(rad) - q[i][1] * sin(rad);
                q[i][1] = t * sin(rad) + q[i][1] * cos(rad);
            }
        }
    }
    else if (choice == 3)
    {
        printf("Enter sx sy sz: ");
        scanf("%f%f%f", &a, &b, &c);
        for (i = 0; i < 8; i++)
        {
            q[i][0] *= a; q[i][1] *= b; q[i][2] *= c;
        }
    }
    else
    {
        printf("Invalid choice.");
        getch();
        return 0;
    }

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    project(p, WHITE);
    project(q, GREEN);
    outtextxy(10, 10, "Original: White   Transformed: Green");
    getch();
    closegraph();
    return 0;
}
