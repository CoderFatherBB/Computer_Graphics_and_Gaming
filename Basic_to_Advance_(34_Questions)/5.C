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

void Midpoint(int r, int xc, int yc)
{
   int P, x, y;
   P = 1 - r;
   x = 0;
   y = r;
   display(x, y, xc, yc);
   do
   {
        if(P <= 0) //Gentle slpe
        {
            x = x + 1;
            P = P + (2*x) + 3;    
        }
        else
        {
            x = x + 1;
            y = y - 1;
            P = P + (2*x) - (2*y) + 5;
        }
        display(x, y, xc, yc);
   }while(x <= y);
}
void main()
{
    int gd, gm, r, xc, yc;
    gd = DETECT;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    Midpoint(150, 320, 240);
    Midpoint(60, 200, 100);
    Midpoint(60, 440, 100);
    Midpoint(30, 260, 200);
    Midpoint(30, 380, 200);
    Midpoint(20, 320, 260);

    getch();
    closegraph();
}