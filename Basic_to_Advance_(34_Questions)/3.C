#include<stdio.h>
#include<graphics.h>

void display(int x, int y, int xc, int yc)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void Bresenham(int r, int xc, int yc)
{
   int S, x, y;
   S = 3 - (2*r);
   x = 0;
   y = r;
   display(x, y, xc, yc);
   do
   {
        if(S <= 0) 
        {
            x = x + 1;
            S = S + (4*x) + 6;    
        }
        else
        {
            x = x + 1;
            y = y - 1;
            S = S + (4*x) - (4*y) + 10;
        }
        display(x, y, xc, yc);
   }while(x <= y);
}
void main()
{
    int gd, gm, r, xc, yc;
    gd = DETECT;

    printf("\nEnter the values of r : ");
    scanf("%d", &r);
    printf("\nEnter the values of xc and yc : ");
    scanf("%d %d", &xc, &yc);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    Bresenham(r, xc, yc);
    getch();
    closegraph();
}