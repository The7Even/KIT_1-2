#include <stdio.h>
#include <conio.h>   

#define KEY_ESC 27
#define KEY_UP (256 + 72)
#define KEY_DOWN (256 + 80)
#define KEY_LEFT (256 + 75)
#define KEY_RIGHT (256 + 77)
int GetKey(void)
{
    int ch = _getch();

    if (ch == 0 || ch == 224)
        // 방향키의 경우 0 또는 224의 값이 먼저 입력됨
        ch = 256 + _getch();
    // 그 다음에 해당 방향키에 따라 72(Up), 
    // 80(Down), 75(Left), 77(Right) 값이 입력됨
    return ch;
}

int main(void)
{
    int ch;

    while ((ch = GetKey()) != KEY_ESC)
    {
        switch (ch)
        {
        case KEY_RIGHT:
            printf("[→] ");
            break;
        case KEY_LEFT:
            printf("[←] ");
            break;
        case KEY_UP:
            printf("[↑] ");
            break;
        case KEY_DOWN:
            printf("[↓] ");
            break;
        }
    }
}
