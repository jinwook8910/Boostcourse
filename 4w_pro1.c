//5자리 숫자 이므로, 0으로 시작하는 숫자는 고려하지 않았다.
//따라서 입력받는 것이 int형이다.

#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define SIZE 5

int main ()
{

    int ori_num; //1번째 입력 받은 정수
    int comp_num; //2번째 입력 받은 정수
    int ori_number[SIZE]; //1번째 정수를 배열에 쪼개 넣음
    int comp_number[SIZE]; //2번째 정수를 배열에 쪼개 넣음

    printf("입력값 : \n");
    scanf("%d", &ori_num);
    scanf("%d", &comp_num);


    for(int i=0; i < SIZE ; i++) // 10으로 나눈 나머지를 배열 한칸씩 넣었음. 자릿수가 반대로 저장되지만 상관없음. 정렬하기때문.
    {
        ori_number[i] = ori_num % 10;
        ori_num = ori_num/10;
        comp_number[i] = comp_num % 10;
        comp_num = comp_num/10;
    }

    // for (int j=0; j < SIZE; j++ )
    // {
    //   printf("%d ", ori_number[j]);
    // }
    // printf("\n");
    // for (int j=0; j < SIZE; j++ )
    // {
    //   printf("%d ", comp_number[j]);
    // }
    // printf("\n");


    int temp; // 임시 저장소
    for (int i=0; i < SIZE; i++) //정렬
    {
        for (int j=0; j < SIZE - i - 1; j++ )
        {
            if (ori_number[j] > ori_number[j+1])
            {
            temp = ori_number[j];
            ori_number[j] = ori_number[j+1];
            ori_number[j+1] = temp;
            }
        }
    }


    for (int i=0; i < SIZE; i++) //정렬
    {
        for (int j=0; j < SIZE - i - 1; j++ )
        {
            if (comp_number[j] > comp_number[j+1])
            {
            temp = comp_number[j];
            comp_number[j] = comp_number[j+1];
            comp_number[j+1] = temp;
            }
        }
    }


    for(int i=0; i < SIZE ; i++)
    {
        if( ori_number[i] == comp_number[i])
        {
            continue;
        }
        else //정렬된 배열간의 요소가 하나라도 같지 않다면 False
        {
            printf("False\n");
            return 1;
        }
    }

    printf("True\n"); //모두 같아서 반복문을 나오면 True
    return 0;

}
