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
	if(P <= 0) 
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

    printf("\nEnter the values of r : ");
    scanf("%d", &r);
    printf("\nEnter the values of xc and yc : ");
    scanf("%d %d", &xc, &yc);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    Midpoint(r, xc, yc);
    getch();
    closegraph();
}