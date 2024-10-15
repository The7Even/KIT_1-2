#include <stdio.h>
#include <conio.h>   
#include <stdlib.h>

#define KEY_ESC 27
#define KEY_UP (256 + 72)
#define KEY_DOWN (256 + 80)
#define KEY_LEFT (256 + 75)
#define KEY_RIGHT (256 + 77)

int initmap[10][10] = { { 1,1,1,1,1,1,1,1,1,1 },
{ 1,0,0,1,0,1,0,2,0,1 },
{ 1,0,2,1,0,1,0,0,0,1 },
{ 1,0,1,0,0,0,0,1,0,1 },
{ 1,0,1,1,1,0,1,0,0,1 },
{ 1,0,0,0,1,0,1,0,1,1 },
{ 1,0,1,0,1,0,1,0,1,1 },
{ 1,0,2,0,0,0,1,0,0,1 },
{ 1,0,0,1,0,1,0,1,3,1 },
{ 1,1,1,1,1,1,1,1,1,1 } };

int playerposition[2] = { 1,1 };
int Healthpoint = 200;
int movecount = 0;
int clear = 0;

void printscreen(void);
void detectmove(void);

int GetKey(void)
{
    int ch = _getch();

    if (ch == 0 || ch == 224)
        ch = 256 + _getch();
    return ch;
}

int main(void)
{
    int ch;
    printscreen();

    while ((ch = GetKey()) != KEY_ESC)
    {
        switch (ch)
        {
        case KEY_RIGHT:
            if (initmap[playerposition[0]][playerposition[1] + 1] != 1)
            {
                playerposition[1] += 1;
                movecount++;
            }
            break;
        case KEY_LEFT:
            if (initmap[playerposition[0]][playerposition[1] - 1] != 1)
            {
                playerposition[1] -= 1;
                movecount++;
            }
            break;
        case KEY_UP:
            if (initmap[playerposition[0] - 1][playerposition[1]] != 1)
            {
                playerposition[0] -= 1;
                movecount++;
            }
            break;
        case KEY_DOWN:
            if (initmap[playerposition[0] + 1][playerposition[1]] != 1)
            {
                playerposition[0] += 1;
                movecount++;
            }
            break;
        }

        detectmove();
        printscreen();

        if (clear != 0)
        {
            if (clear == 1)
                printf("\n>> 축하하셨습니다. 이동횟수 %d회로 클리어하셨습니다. <<", movecount);
            else
                printf("\n >> 체력이 0이 되어 게임오버 되었습니다. <<");
           break;
        }
    }

    return 0;
}

void printscreen(void)
{
    int map[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = initmap[i][j];
        }
    }

    map[playerposition[0]][playerposition[1]] = 4;

    system("cls");

    printf("유저 : ● / 함정 : ※ / 벽 : ■ / 골인지점 : ◈\n\n");
    printf(">>> 이동 횟수 : %d\n\n", movecount);
    printf(">>> HP %d / 200\n(함정을 밟을 경우 100이 차감됩니다.)\n\n", Healthpoint);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] == 1)
                printf("■");
            else if (map[i][j] == 2)
                printf("※");
            else if (map[i][j] == 3)
                printf("◈");
            else if (map[i][j] == 0)
                printf(" ");
            else if (map[i][j] == 4)
                printf("●");
        }

        printf("\n");
    }
}

void detectmove(void)
{
    if (initmap[playerposition[0]][playerposition[1]] == 2)
    {
        Healthpoint -= 100;
        initmap[playerposition[0]][playerposition[1]] = 0;
        if (Healthpoint == 0)
            clear = 2;
    }
    else  if (initmap[playerposition[0]][playerposition[1]] == 3)
    {
        clear = 1;
    }
}
