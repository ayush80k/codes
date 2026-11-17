#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawEdges(int x[], int y[], int edges[][2], int count)
{
    int i;
    for (i = 0; i < count; i++)
        line(x[edges[i][0]], y[edges[i][0]],
             x[edges[i][1]], y[edges[i][1]]);
}

int main()
{
    int gd = DETECT, gm, choice, i;
    int x[8], y[8];
    int cubeE[12][2] = {
        {0,1},{1,2},{2,3},{3,0},{4,5},{5,6},
        {6,7},{7,4},{0,4},{1,5},{2,6},{3,7}
    };
    int pyrE[8][2] = {
        {0,1},{1,2},{2,3},{3,0},{0,4},{1,4},{2,4},{3,4}
    };

    printf("Select 3D object\n1. Cube\n2. Cuboid\n3. Pyramid\nChoice: ");
    scanf("%d", &choice);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setcolor(WHITE);

    if (choice == 1)
    {
        x[0]=220; y[0]=170; x[1]=360; y[1]=170;
        x[2]=360; y[2]=310; x[3]=220; y[3]=310;
        x[4]=270; y[4]=120; x[5]=410; y[5]=120;
        x[6]=410; y[6]=260; x[7]=270; y[7]=260;
        drawEdges(x, y, cubeE, 12);
        outtextxy(300, 350, "Cube");
    }
    else if (choice == 2)
    {
        x[0]=180; y[0]=190; x[1]=420; y[1]=190;
        x[2]=420; y[2]=310; x[3]=180; y[3]=310;
        x[4]=240; y[4]=120; x[5]=480; y[5]=120;
        x[6]=480; y[6]=240; x[7]=240; y[7]=240;
        drawEdges(x, y, cubeE, 12);
        outtextxy(300, 350, "Cuboid");
    }
    else if (choice == 3)
    {
        x[0]=210; y[0]=300; x[1]=420; y[1]=300;
        x[2]=470; y[2]=360; x[3]=260; y[3]=360;
        x[4]=330; y[4]=100;
        drawEdges(x, y, pyrE, 8);
        outtextxy(300, 400, "Pyramid");
    }
    else
        outtextxy(250, 220, "Invalid choice");

    getch();
    closegraph();
    return 0;
}
