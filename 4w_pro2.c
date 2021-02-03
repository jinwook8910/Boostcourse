
#include <stdio.h>
#include <cs50.h>

#define SIZE 5

int main()
{
    int house[SIZE] = { 0, 3, 11, 5, 5}; //5명의 친구가 사는 집의 위치

    //각 거리의 합. (0-a) + (3-a) + ... (5-a) = 24-5a..
    //극단적인 예시. 0, 0, 0, 0, 100.   -> 중앙값 0, 평균값 20.
    // 거리합 : 중앙값 0의 경우 -> 100, 평균값 20의 경우 -> 160

    //http://kr.brainworld.com/brainWorldMedia/ContentView.aspx?fromBoard=allNewsList&fromCategory=Opinion&contIdx=12095
    //직선상에 집들중에 중간값에 사는것이 정답이다.
    //집의 갯수가 짝수여도 중간에 위치한 두 점을 포함하여 그 두집 사이 아무 점에서도 모든 다른 집들에 대한 거리합은 최소로 같다.

    int temp;
    for (int i=0; i < 5; i++)
    {
        for (int j=0; j < 5 - i - 1; j++ )
        {
            if (house[j] > house[j+1])
            {
                temp = house[j];
                house[j] = house[j+1];
                house[j+1] = temp;
            }
        }
    }

    printf("%d\n", house[SIZE/2]);

}
