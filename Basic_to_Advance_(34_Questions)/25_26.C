#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int xmin, ymin, xmax, ymax;

typedef struct coordinate
{
    int x, y;
    char code[4];
} PT;

void drawline(PT p1, PT p2);
PT setcode(PT p);
int visibility(PT p1, PT p2);
PT resetendpt(PT p1, PT p2);

int computeCode(int x, int y)
{
    int code = INSIDE;
    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;
    return code;
}

void cohenSutherlandClip(int x1, int y1, int x2, int y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;
    while (1)
    {
        if (!(code1 | code2))
        {
            accept = 1;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int x, y;
            int codeOut = code1 ? code1 : code2;
            if (codeOut & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }
            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cleardevice();
        setcolor(RED);
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    }
}

void cohen()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    printf("Enter the minimum and maximum coordinates of\nwindow(xmin ymin xmax ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);
    
    printf("Enter the endpoints of line(x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    
    getch();
    cohenSutherlandClip(x1, y1, x2, y2);
    
    getch();
    closegraph();
}

void mid()
{
    int gd = DETECT, gm, v;
    PT p1, p2, ptemp;
    
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    // cleardevice();
    
    printf("Enter the minimum and maximum coordinates of\nwindow(xmin ymin xmax ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);
    
    printf("Enter the endpoints of line(x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
    setcolor(WHITE);
    line(p1.x, p1.y, p2.x, p2.y);
        
    getch();
        
    cleardevice();
    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(GREEN);
    midsub(p1, p2);
    
    getch();
    closegraph();
}

midsub(PT p1, PT p2)
{
    PT mid;
    int v;
    p1 = setcode(p1);
    p2 = setcode(p2);
    v = visibility(p1, p2);
    switch (v)
    {
        case 0:
            line(p1.x, p1.y, p2.x, p2.y);
        break;
        
        case 1:
        break;

        case 2:
            mid.x = p1.x + (p2.x - p1.x) / 2;
            mid.y = p1.y + (p2.y - p1.y) / 2;
            midsub(p1, mid);
            mid.x = mid.x + 1;
            mid.y = mid.y + 1;
            midsub(mid, p2);
        break;
    }
}

PT setcode(PT p)
{
    PT ptemp;
    if (p.y <= ymin)
        ptemp.code[0] = '1';
    else
        ptemp.code[0] = '0';
    if (p.y >= ymax)
        ptemp.code[1] = '1';
    else
        ptemp.code[1] = '0';
    if (p.x >= xmax)
        ptemp.code[2] = '1';
    else
        ptemp.code[2] = '0';
    if (p.x <= xmin)
        ptemp.code[3] = '1';
    else
        ptemp.code[3] = '0';
    ptemp.x = p.x;
    ptemp.y = p.y;
    return (ptemp);
}

int visibility(PT p1, PT p2)
{
    int i, flag = 0;
    for (i = 0; i < 4; i++)
    {
        if ((p1.code[i] != '0') || (p2.code[i] != '0'))
            flag = 1;
    }
    if (flag == 0)
        return (0);
    for (i = 0; i < 4; i++)
    {
        if ((p1.code[i] == p2.code[i]) && (p1.code[i] == '1'))
            flag = 0;
    }
    if (flag == 0)
        return (1);
    return (2);
}

void main()
{
    int choice;
    
    while(1)
    {
        printf("1. Cohen Sutherland Line Clipping Algorithm\n");
        printf("2. Mid Point Sub Division Line Clipping Algorithm\n");
        printf("3. Exit\n");
        printf(": ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                cohen();
            break;

            case 2:
                mid();
            break;

            case 3:
                exit(0);
        }
    }
}
