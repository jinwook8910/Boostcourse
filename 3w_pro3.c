//#배열 #Queue #switch문 #반복문 #표준입출력

/*
배열을 이용하여 Queue 를 만들어 보자.
특정 업무를 할 때, 우리는 일을 들어온 순서대로 해야할 때가 있다. 은행 업무를 예를 들어보자.
은행업무를 보기 위한 고객들이 10명이 있다고 치고, 각자 대기표가 있다.
그럼 은행원들은 각자 업무가 끝나면 대기한 고객을 순서대로 뽑아야 할 것이다.
이때 필요한 것이 Queue 이다.
(1) 대기표를 뽑는다 (Queue 에 데이터를 삽입).
(2) 대기인원을 보여준다 (queue 에 쌓여있는 데이터 조회).
(3) 순서대로 대기인원을 호출한다 (queue 를 하나씩 pop 한다).


- Queue 자료구조를 array를 이용해 구현
1. add (1), pop (2), display (3), quit (4) 기능 구현
2. 입력 한 옵션 (1, 2, 3, 4) 에 따라 switch 문을 사용하여 각각의 기능을 수행하도록 구현
3. 필요한 함수 목록: insert(), delete(), display()
    - 각 함수의 파라미터는 필요하면 정의하기
4. add() 함수의 정의
    - queue 가 꽉찼는지 확인 (Queue 의 max 크기는 10으로 정의), queue 가 꽉찼으면 “Queue가 꽉 찼습니다.” 를 출력
    - queue 에 삽입이 가능하면, 값을 입력 받아 queue 배열에 삽입 (hint: front, rear 변수를 사용하여 queue 의 현재 위치를 저장한다)
5. pop() 함수의 정의
    - queue 가 비었는지 확인, 비었으면 “Queue가 비었습니다.” 를 출력
    - queue 가 비어있지 않으면, 가장 먼저 들어온 순서로 값을 하나 가져와 출력 (hint: front 변수값 조정 필요)
6. display() 함수의 정의
    - 반복문을 사용하여 배열의 모든 요소를 출력 (hint: front, rear 변수 범위로 배열값을 출력)


TODO: 여기서 출력 예시 보여주기
*/


//큐에 자료를 넣을떄, rear가 증가하고, 자료를 빼낼때 front가 증가한다.
//자료를 넣을때는 공간이 있는지 확인해야하고 이는 rear와 SIZE의 크기로 비교한다.
//자료를 뺄때는 자료가 있는지 확인해야하고 이는 rear와 front가 같은지 확인한다.
//그리고 뺄때 마지막 자료를 뺸것이면 rear와 front를 모두 0으로 초기화해준다.
#include <stdio.h>
#include <cs50.h>

const int SIZE=3;
int queue[100]; //큐의 크기는 충분히 커야 한다. 배열의 한계...?
int front = 0;
int rear = 0;

void add();
void pop();
void display();

int main (void)
{
    while(true)
    {
         printf("1. 삽입 \n2. 삭제 \n3. 조회 \n4. 종료\n");
        int menu = get_int("입력 : ");


        switch(menu)
        {
            case 1: //큐가 비어있는지 확인후 삽입할 내용 입력받고 넣는다.
            add();
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            return 0;


        }
    }

}

void add()
{
    //삽입되면 값은 queue[front]에 들어가고, queue[rear]에는 값이 없고, queue[rear-1]이 가장 최근에 넣은 값이다.
    // -> 이방식은 잘못되었다. front에 삽입하면 제일 앞의 위치를 잃어버린다. 삽입과 함께 이전 자료의 위치를 놓친다.
    // 즉, 삽입은 rear를 기준으로 넣어야 한다.
    //가득 찼는지 확인하기 위해서는 front와 rear의 차이가 SIZE(10)이면 가득 찬 상태이다.
    if ( rear - front >= SIZE ) // 큐가 가득 찼는지 확인. rear은 계속 증가할 수 있다.
    {
        printf("Queue가 꽉 찼습니다.\n");
        return;
    }

    int a = get_int("삽입할 값 :");
    queue[rear] = a; //여기서 자료를 넣는 기준을 rear로 잡는것이 핵심이다.
    rear++;

}

void pop()
{
    //뺄때는 큐에 값이 존재하는지 확인해야한다.
    //뺄때는 front의 값을 출력해주면서 front를 증가시킨다. 이때 front와 rear가 같아지면 큐가 완전히 비워진 것이다.
    //비워지면 0으로 초기화해주자. rear의 값이 큐 사이즈를 넘어가는 불상사를 방지할 수 있다. 완벽히 방지 할 순 없지만.
    if ( rear - front <= 0 )
    {
        printf("Queue가 비었습니다.\n");
        return;
    }

    printf("큐에서 삭제됨 : %d\n", queue[front]);
    front++;

    if ( rear == front ) //마지막 자료를 뽑았을때 rear와 front의 위치를 queue의 제일 앞으로 이동
    {
        rear = 0;
        front = 0;
    }

}

void display()
{
    if( rear == front)
    {
        printf("조회할 자료가 없습니다.\n");
        return;
    }

    printf("큐 : ");
    for( int i = front; i < rear ; i++ )
    {
        printf("%d ",queue[i]);
    }
    printf("\n");

}
