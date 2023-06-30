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

void Bresenham(int x1, int y1, int x2, int y2)
{
   int G, dx, dy;
   dx = x2 - x1;
   dy = y2 - y1;
   dx = abs(dx);
   dy = abs(dy);

   if(dx > dy) //Gentle slpe
   {
	G = (2*dy) - dx;
	do
	{
	    if(G >= 0)
	    {
		x1 = x1 + 1;
		y1 = y1 + 1;
		G = G + (2*dy) - (2*dx);
	    }
	    else
	    {
		x1 = x1 + 1;
		G = G + (2*dy);
	    }
	    putpixel(x1, y1, WHITE);
	}while(x1 <= x2);
   }
   else //Steep slope
   {
	G = (2*dx) - dy;
	do
	{
	    if(G >= 0)
	    {
		x1 = x1 + 1;
		y1 = y1 + 1;
		G = G + (2*dx) - (2*dy);
	    }
	    else
	    {
		y1 = y1 + 1;
		G = G + (2*dx);
	    }
	    putpixel(x1, y1, WHITE);
	}while(y1 <= y2);
   }
}

void main()
{
    int gd, gm, r, xc, yc;
    gd = DETECT;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    Bresenham(100, 200, 100, 300);
    Bresenham(100, 200, 250, 200);
    Bresenham(250, 130, 250, 200);
    Bresenham(250, 130, 500, 130);
    Bresenham(500, 130, 500, 200);
    Bresenham(500, 200, 570, 200);
    Bresenham(570, 200, 570, 300);
    Bresenham(100, 300, 570, 300);
    Midpoint(40, 180, 340);
    Midpoint(40, 480, 340);
    
    getch();
    closegraph();
}