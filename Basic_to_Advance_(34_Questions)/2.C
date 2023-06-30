#include <stdio.h>
#include <graphics.h>

void Bresenham(int x1, int y1, int x2, int y2)
{
	int G, dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;
	dx = abs(dx);
	dy = abs(dy);

	if (dx > dy) // Gentle slpe
	{
		G = (2 * dy) - dx;
		do
		{
			if (G >= 0)
			{
				x1 = x1 + 1;
				y1 = y1 + 1;
				G = G + (2 * dy) - (2 * dx);
			}
			else
			{
				x1 = x1 + 1;
				G = G + (2 * dy);
			}
			putpixel(x1, y1, WHITE);
		} while (x1 <= x2);
	}
	else // Steep slope
	{
		G = (2 * dx) - dy;
		do
		{
			if (G >= 0)
			{
				x1 = x1 + 1;
				y1 = y1 + 1;
				G = G + (2 * dx) - (2 * dy);
			}
			else
			{
				y1 = y1 + 1;
				G = G + (2 * dx);
			}
			putpixel(x1, y1, WHITE);
		} while (y1 <= y2);
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
	Bresenham(x1, y1, x2, y2);
	getch();
	closegraph();
}