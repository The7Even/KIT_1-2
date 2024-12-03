#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Point
{
    int x;
    int y;
};
typedef struct Point Point;

int main(void)
{
    // 바이너리 모드로 10개의 Point 값(x, y)을 파일로 저장한다.
    srand(time(NULL));
    FILE* fp = fopen("point.txt", "wb");
    for (int i = 0; i < 10; i++)
    {
        Point pt = { rand() % 10, rand() % 10 };
        fwrite(&pt, sizeof(Point), 1, fp);
    }
    fclose(fp);

    // point.txt 파일을 읽고쓰기/바이너리모드로 연다. 읽기모드가 기본이다. "rb+"
    FILE* fp2 = fopen("point.txt", "rb+");
    int option = 0;
    int selection = 0;
    Point Current = { 0,0 };
        // 메뉴에 따라 수행하기를 반복 수행한다.
    while (1)
    {
        while (1)
        {
            printf(">>> 메뉴 선택(수정>1, 출력>2 / 종료하려면 0 입력) : ");
            scanf_s("%d", &option);
            if (option == 0 || option == 1 || option == 2)
                break;
        } 

        // 0번 옵션 : 종료하기
        if (option == 0)
        {
            printf("프로그램을 종료합니다.");
            return 0;
        }
        // 1번 옵션 : 수정하기
        else if (option == 1)
        {
            printf("수정할 Point의 Index 입력(0~9) : ");
            scanf_s("%d", &selection);

            Point Newpoint;
            printf("수정할 Point의 새 좌표 입력 : ");
            scanf_s("%d %d", &Newpoint.x, &Newpoint.y);

            fseek(fp2, sizeof(int) * 2 * selection, SEEK_SET);
            fwrite(&Newpoint, sizeof(Point), 1, fp);
        }
        // 2번 옵션 : 출력하기
        else
        {
            for (int i = 0; i < 10; i++)
            {
                fseek(fp2, sizeof(int) * 2 * i, SEEK_SET);
                Current.x = getc(fp2);
                fseek(fp2, sizeof(int) * (2 * i + 1), SEEK_SET);
                Current.y = getc(fp2);
                printf("(%d, %d) ", Current.x, Current.y);
            }
            printf("\n");
        }
     }

    // 파일을 닫는다.
    fclose(fp);
}
