#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x;
    int y;
};
typedef struct Point Point;

int main(void)
{
    int city_count;
    Point* data;
    // cities.txt 파일을 열고 fscanf 함수를 사용하여 도시 개수를 읽어들인다.
    FILE* fp = fopen("cities.txt", "rt");
    fscanf_s(fp, "%d", &city_count);
        // 도시 개수만큼의 좌표를 저장하기 위해 메모리 동적 할당을 받는다.
    data = malloc(sizeof(Point) * city_count);
        // 각 도시의 좌표를 읽어들이고 파일을 닫는다.
    for (int i = 0; i < 10; i++)
    {
        fscanf_s(fp, "%d %d", &data[i].x, &data[i].y);
    }
    fclose(fp);
        // 각 도시의 좌표를 화면에 출력한다.
    for (int i = 0; i < 10; i++)
    {
        printf("[city %d] (%d, %d)\n", i + 1, data[i].x, data[i].y);
    }
        // data 메모리를 해제한다.    
    free(data);
}
