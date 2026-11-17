#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void drawCube(float p[8][3], int color)
{
    int i, x[8], y[8];
    int e[12][2] = {
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
        line(x[e[i][0]], y[e[i][0]], x[e[i][1]], y[e[i][1]]);
}

int main()
{
    int gd = DETECT, gm, i, axis;
    float p[8][3], q[8][3];
    float tx, ty, tz, sx, sy, sz, angle, rad, t;

    {
        float base[8][3] = {
            {-50,-50,-50},{50,-50,-50},{50,50,-50},{-50,50,-50},
            {-50,-50,50},{50,-50,50},{50,50,50},{-50,50,50}
        };
        for (i = 0; i < 8; i++)
        {
            p[i][0] = base[i][0];
            p[i][1] = base[i][1];
            p[i][2] = base[i][2];
        }
    }

    printf("Enter scaling factors sx sy sz: ");
    scanf("%f%f%f", &sx, &sy, &sz);
    printf("Enter rotation axis (1-X 2-Y 3-Z) and angle: ");
    scanf("%d%f", &axis, &angle);
    printf("Enter translation tx ty tz: ");
    scanf("%f%f%f", &tx, &ty, &tz);

    rad = angle * PI / 180.0;
    for (i = 0; i < 8; i++)
    {
        q[i][0] = p[i][0] * sx;
        q[i][1] = p[i][1] * sy;
        q[i][2] = p[i][2] * sz;

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

        q[i][0] += tx;
        q[i][1] += ty;
        q[i][2] += tz;
    }

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    drawCube(p, WHITE);
    drawCube(q, GREEN);
    outtextxy(10, 10, "Composite: Scaling, Rotation, Translation");
    getch();
    closegraph();
    return 0;
}
