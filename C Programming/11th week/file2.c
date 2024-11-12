#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>   
#include <Windows.h>

#define KEY_ESC 27
#define KEY_UP (256 + 72)
#define KEY_DOWN (256 + 80)
#define KEY_LEFT (256 + 75)
#define KEY_RIGHT (256 + 77)

void Initialize(void);
int GetKey(void);
void SetCursorVisible(int visible);
void DrawBoard(int** p);
void Shuffle(int** p);
void Swap(int* x, int* y);
int CheckSuccess(void);

int size = 3;
int** target_board = NULL;
int** current_board = NULL;
int zero_row, zero_col;

int main(void)
{
    srand(time(NULL));
    SetCursorVisible(0);

    printf("게임판의 크기를 설정해 주십시오. >>> ");
    scanf_s("%d", &size);

    Initialize();
    Shuffle(current_board);
    DrawBoard(current_board);

    while (1)
    {
        if (CheckSuccess())
        {
            printf("성공!!!\n");
            break;
        }

        int key = GetKey();
        // 방향키 처리
        switch (key)
        {
            case KEY_RIGHT:
                if (zero_col != size - 1)
                {
                    Swap(&current_board[zero_row][zero_col], &current_board[zero_row][zero_col + 1]);
                    zero_col++;
                }
                break;

            case KEY_LEFT:

                if (zero_col != 0)
                {
                    Swap(&current_board[zero_row][zero_col], &current_board[zero_row][zero_col - 1]);
                    zero_col--;
                }
                break;

            case KEY_UP:

                if (zero_row != 0)
                {
                    Swap(&current_board[zero_row][zero_col], &current_board[zero_row - 1][zero_col]);
                    zero_row--;
                }
                break;

            case KEY_DOWN:

                if (zero_row != size - 1)
                {
                    Swap(&current_board[zero_row][zero_col], &current_board[zero_row + 1][zero_col]);
                    zero_row++;
                }
                break;
        }

        DrawBoard(current_board);
    }

    printf("프로그램 종료\n");

    return 0;
}

void Initialize(void)
{
    target_board = malloc(sizeof(int*) * size); // 1차원 동적 할당
    for (int i = 0; i < size; i++)
        target_board[i] = malloc(sizeof(int*) * size); // 2차원 동적 할당

    int num = 1;
    for (int i = 0; i < size; i++) // 목표 보드 생성 - 완성된 보드 (이 형태가 되면 성공 처리)
        for (int j = 0; j < size; j++)
        {
            target_board[i][j] = num;
            num++;
        }
    target_board[size - 1][size - 1] = 0; // 마지막 칸을 공백으로 생성

    current_board = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++)
        current_board[i] = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) // 플레이 보드 생성 - num변수 안쓰고 이미 만들어진 target_board를 이용하여 생성. >> 마지막칸 공백으로 바꿔주는 과정도 포함
        for (int j = 0; j < size; j++)
            current_board[i][j] = target_board[i][j];

    zero_row = size - 1; // 0의 위치가 어디인지 저장하기 
    zero_col = size - 1; // size = 3일때 위치는 [2][2]
}

void DrawBoard(int** p)
{
    system("cls");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (p[i][j] == 0)
                printf("%3s", "   ");
            else
                printf("%3d", p[i][j]);
        }
        printf("\n");
    }
}

void Shuffle(int** p) // 초기 설정에서 사용하는 섞기 함수
{
    int shuffle = rand() % 50 + 200; // 200~250회 위치 변경
    for (int i = 0; i < shuffle; i++)
    {
        while (1)
        {
            int didshuffle = 0;
            int change_pos = rand() % 4 + 1; // 1 > 오른, 2 > 왼, 3 > 상, 4 > 하
            switch (change_pos)
            {
            case 1:
                if (zero_col != size - 1)
                {
                    Swap(&current_board[zero_row][zero_col], &current_board[zero_row][zero_col + 1]);
                    zero_col++;
                    didshuffle++;
                }
                break;

            case 2:

                if (zero_col != 0)
                {
                    Swap(&current_board[zero_row][zero_col], &current_board[zero_row][zero_col - 1]);
                    zero_col--;
                    didshuffle++;
                }
                break;

            case 3:

                if (zero_row != 0)
                {
                    Swap(&current_board[zero_row][zero_col], &current_board[zero_row - 1][zero_col]);
                    zero_row--;
                    didshuffle++;
                }
                break;

            case 4:

                if (zero_row != size - 1)
                {
                    Swap(&current_board[zero_row][zero_col], &current_board[zero_row + 1][zero_col]);
                    zero_row++;
                    didshuffle++;
                }
                break;
            }

            if (didshuffle == 1)
                break;
        }
    }
}

void Swap(int* x, int* y) // 두개의 위치를 변경한다. 방향키를 눌렀을때 0의 위치와 방향키를 받은 방향의 위치를 서로 맞바꾼다.
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int CheckSuccess(void)
{
    int stack = 0;
    for (int i = 0; i < size ; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (current_board[i][j] == target_board[i][j])
                stack++;
        }
    }

    if (stack == size * size)
        return 1;
    else
        return 0;
}

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

void SetCursorVisible(int visible)
{
    CONSOLE_CURSOR_INFO ci = { 100, visible };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}
