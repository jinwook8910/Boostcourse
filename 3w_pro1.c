//네이버 부스트 코스 3주차 1번문제
/*
1. 미션 제목
    학점을 계산해보자!

 

2. 지시문
    - 학생의 점수로 학점을 구하는 프로그램을 작성하시오.
    - 키보드에서 입력받은 성적 (0 ~ 100 점) 의 유효성을 체크
    - 학점은 배열을 이용하여 초기화 (아래 “학점 테이블” 참조)
    - 학점은 “학점” 과 같이 계산하는데, 반드시 “학점 테이블”을 사용하여 계산하고 학점도 “학점 테이블”의 내용을 출력
    - 성적을 입력하여 계속 학점을 구하며 특별한 문자인 “999” 를 입력하면 프로그램을 종료

*/

#include <stdio.h>
#include <cs50.h>
#include <string.h> // 이부분을 안넣어도 string 배열을 선언할 수 있었다..!

// 학점 비교하는데 중복으로 사용될 상수는 추후에 변경이 가능하도록, 또 실수하지 않도록
// 상수로 선언하였다.
const int NUMBER_OF_GRADES=9;
const int SCORE[NUMBER_OF_GRADES]={95,90,85,80,75,70,65,60,0};
const string GRADES[NUMBER_OF_GRADES]={"A+","A","B+","B","C+","C","D+","D","F"};
const int EXIT = 999; //이부분은 반복은 아니지만 상수로 사용했다..

int main (void)
{

    printf("학점 프로그램 \n종료를 원하면 \"999\" 를 입력 \n[학점 테이블]\n");

    //학점 테이블을 출력한다.
    printf("점수 : ");
    for(int i = 0; i < NUMBER_OF_GRADES ; i++ )
    {
        printf("%8d", SCORE[i]);
    }
    printf("\n");

    printf("학점 : ");
    for(int i = 0; i < NUMBER_OF_GRADES ; i++ )
    {
        printf("%8s", GRADES[i]);
    }
    printf("\n");

    //학점을 입력받고 비교하는 부분을 반복한다.
    //1주차에 배운 전화번호부 방식을 쓰려했지만, 이번 문제는 학생의 점수와
    // 정확히 같은 값이 있는게 아니라 범위라서 다른 방식 사용

    while(true){//무한 반복문을 쓰고, 내부에서 특정 조건에 닿으면 break로 빠져나온다.
        int num = get_int("성적을 입력하세요 (0 ~ 100) : ");

        if( num == EXIT)//종료 버튼
        {
            printf("학점 프로그램을 종료합니다.\n");
            break;
        }
        else if( num > 100 || num < 0)
        {
            printf("성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n");
            continue;
            //올바르지 않은 성적은 비교할 필요가 없어서 다음 코드를 생략하고
            //바로 다시 반복문의 처음으로 돌아가도록 continue를 사용했다.
        }

    // 상수를 변경해도 코드를 그대로 쓸수 있도록 짜보자. 점수가 0 ~ 100사이인 것은 변하지 않는다.
    // 학점테이블의 0번째 점수기준 보다 크거나 같은지 본다. true면 그 값을 출력한다.
    // false면 다음 인덱스로 넘어간다.
        for(int i = 0; i < NUMBER_OF_GRADES ; i++ )
        {
            if( num >= SCORE[i])
            {
                printf("학점은 %s입니다.\n", GRADES[i]);
                break;
            }
        }
    }


}
