#include <stdio.h>
#include<math.h>
#include <graphics.h>

void draw(int arr[5][2], int n)
{
    int i, x, y, x1, y1;
    for (i = 0; i < n; i++)
    {
	x = arr[i][0];
	y = arr[i][1];
	if (i != 0)
	    line(x1, y1, x, y);
	x1 = x;
	y1 = y;
    }
    line(x1, y1, arr[0][0], arr[0][1]);
}

void printMatrix(int matrix[][2], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
	for (j = 0; j < 2; j++)
	{
	    printf("%d ", matrix[i][j]);
	}
	printf("\n");
    }
}

void translation(int a[5][2], int n, int tx, int ty, int mul[5][2])
{
    int i, j, k;
    int at[5][2];
    int b[3][3]; // transfomation matrix
    int h[5][3]; // homogenous co-ordinates
    int x[5][2]; // for display
    b[0][0] = 1;
    b[0][1] = 0;
    b[0][2] = 0;
    b[1][0] = 0;
    b[1][1] = 1;
    b[1][2] = 0;
    b[2][0] = tx;
    b[2][1] = ty;
    b[2][2] = 1;

    for (i = 0; i < n; i++)
    {
	at[i][0] = a[i][0] - 320;
	at[i][1] = 240 - a[i][1];
    }
    for (i = 0; i < n; i++)
    {
	h[i][0] = at[i][0];
	h[i][1] = at[i][1];
	h[i][2] = 1;
    }
    for (i = 0; i < n; i++)
    {
	for (j = 0; j < 3; j++)
	{
	    mul[i][j] = 0;
	    for (k = 0; k < 3; k++)
	    {
		mul[i][j] += h[i][k] * b[k][j];
	    }
	}
    }
    for (i = 0; i < n; i++)
    {
	mul[i][0] += 320;
	mul[i][1] = 240 - mul[i][1];
    }
    // coverting matrix again in 2 columns for display
    for (i = 0; i < n; i++)
    {
	x[i][0] = mul[i][0];
	x[i][1] = mul[i][1];
    }

    setcolor(RED);
    draw(x, n);
}

void translation2(int a[5][2], int n, int tx, int ty, int mul[5][2])
{
    int i, j, k;
    int at[5][2];
    int b[3][3]; // transfomation matrix
    int h[5][3]; // homogenous co-ordinates
    int x[5][2]; // for display
    b[0][0] = 1;
    b[0][1] = 0;
    b[0][2] = 0;
    b[1][0] = 0;
    b[1][1] = 1;
    b[1][2] = 0;
    b[2][0] = tx;
    b[2][1] = ty;
    b[2][2] = 1;

    for (i = 0; i < n; i++)
    {
	at[i][0] = a[i][0] - 320;
	at[i][1] = 240 - a[i][1];
    }
    for (i = 0; i < n; i++)
    {
	h[i][0] = at[i][0];
	h[i][1] = at[i][1];
	h[i][2] = 1;
    }
    for (i = 0; i < n; i++)
    {
	for (j = 0; j < 3; j++)
	{
	    mul[i][j] = 0;
	    for (k = 0; k < 3; k++)
	    {
		mul[i][j] += h[i][k] * b[k][j];
	    }
	}
    }
    for (i = 0; i < n; i++)
    {
	mul[i][0] += 320;
	mul[i][1] = 240 - mul[i][1];
    }
    // coverting matrix again in 2 columns for display
    for (i = 0; i < n; i++)
    {
	x[i][0] = mul[i][0];
	x[i][1] = mul[i][1];
    }

    setcolor(BLUE);
    draw(x, n);
}

void main()
{
    int gd = DETECT, gm;
    int tx1,tx2,tx3,ty1,ty2,ty3;
    int i, j, n, a[5][2], b[5][2], c[5][2], mul[5][2], mul2[5][2];
    int ch;
    clrscr();

    printf("\nEnter number of vertices : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
	printf("Enter x%d and y%d : ", i + 1, i + 1);
	scanf("%d%d", &a[i][0], &a[i][1]);
	a[i][0] += 320;
	a[i][1] = 240 - a[i][1];
    }

    for (i = 0; i < n; i++)
    {
	for (j = 0; j < 2; j++)
	{
	    c[i][j] = a[i][j];
	}
    }

    do
    {
	printf("\nEnter\n1. Additive Nature\n2. Commutative Nature\n3. Exit\n");
	scanf("%d", &ch);

	switch (ch)
	{

	    case 1: printf("Enter the 1st translating factors: ");
		    scanf("%d %d", &tx1,&ty1);
		    printf("Enter the 2nd translating factors: ");
		    scanf("%d %d", &tx2,&ty2);
		    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

		    draw(a, n);
		    line(320, 0, 320, 479);
		    line(0, 240, 679, 240);

		    printf("For LHS\nTranslating for fators %d %d", tx1,ty1);
		    translation(a,n,tx1,ty1,mul);
		    getch();

		    printf("\nTranslating for factors %d %d\n", tx2,ty2);
		    translation(mul,n,tx2,ty2,mul2);
		    printMatrix(mul, n);
		    getch();
		    closegraph();

		    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
		    draw(c, n);
		    line(320, 0, 320, 479);
		    line(0, 240, 679, 240);

		    tx3 = tx1 + tx2;
		    ty3 = ty1 + ty2;
		    printf("\nFor RHS\nTranslating for factors %d %d\n", tx3,ty3);
		    translation2(a, n, tx3, ty3, mul);
		    printMatrix(a, n);
		    getch();
		    closegraph();

		    printf("We saw that the final matrices for LHS and RHS are same.\nTherefore, Translation of object is Additive in nature.");
		    closegraph();
		    getch();
		    break;

	    case 2: printf("Enter the 1st translating factors: ");
		    scanf("%d %d", &tx1,&ty1);
		    printf("Enter the 2nd translating factors: ");
		    scanf("%d %d", &tx2,&ty2);
		    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

		    draw(a, n);
		    line(320, 0, 320, 479);
		    line(0, 240, 679, 240);

		    printf("For LHS\nTranslating for fators %d %d", tx1,ty1);
		    translation(a,n,tx1,ty1,mul);
		    getch();

		    printf("\nTranslating for factors %d %d\n", tx2,ty2);
		    translation(mul,n,tx2,ty2,mul2);
		    printMatrix(mul, n);
		    getch();
		    closegraph();

		    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
		    draw(c, n);
		    line(320, 0, 320, 479);
		    line(0, 240, 679, 240);

		    printf("For RHS\nTranslating for factors %d %d\n", tx2,ty2);
		    translation2(c,n,tx2,ty2,mul);
		    getch();

		    printf("\nTranslating for fators %d %d\n", tx1,ty1);
		    translation2(mul,n,tx1,ty1,mul2);
		    printMatrix(mul, n);
		    getch();
		    closegraph();

		    printf("We saw that the final matrices for LHS and RHS are same.\nTherefore, Translation of object is Commutative in nature.");
		    getch();
		    closegraph();
		    break;

	    case 3: exit(0);

            default:printf("Invalid input");
                    break;
        }
    }
    while(ch!=3);
}