#include<stdio.h>
#include<graphics.h>

void DDA(int x1, int y1, int x2, int y2)
{
    int xd, yd, dx, dy;
    float xc, yc, m;

    dx = x2 - x1;
    dy = y2 - y1;
    m = dy / dx;

    if(abs(dx) > abs(dy)) //Gentle slope
    {
        yc = y1;
        do
        {
            x1 = x1 + 1;
            yc = yc + m;
            yd = yc + 0.5;
            putpixel(x1, yd, WHITE);
        }while(x1 <= x2);
        }
    else //Steep slope
    {
        xc = x1;
        do
        {
            y1 = y1 + 1;
            xc =  xc + (1/m);
            xd = xc + 0.5;
            putpixel(xd, y1, WHITE);
        } while(y1 <= y2);
    }
}
void main()
{
    int gd, gm, x1, y1, x2, y2;
    gd = DETECT;

    printf("\nEnter the values of x1 and y1 : ");
    scanf("%d %d", &x1, &y1);
    printf("\nEnter the values of x2 and y2 : ");
    scanf("%d %d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    DDA(x1, y1, x2, y2);
    getch();
    closegraph();
}