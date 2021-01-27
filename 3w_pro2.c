//https://dojang.io/mod/page/view.php?id=294 배열 0으로 초기화
#include <stdio.h>
#include <cs50.h>

#define SIZE 500000

int main(int arge, char*argv[]) {

    // 파일 입출력을 명령행 인자로 간단히 하다니...
    // FILE *fp;
    // fp = fopen("test.txt", "w");
    int n;

    scanf("%d", &n);

    // 1부터 N의 숫자중 K가 빠진 배열
    int partArr[SIZE];
    int lengthOfPartArr = n-1;

    for(int i=0; i < lengthOfPartArr; i++){
        scanf("%d", &partArr[i]);
    }

    // TODO: n과 partArr를 이용하여, K를 구하라

    //어떻게 하면 효율적으로 탐색할 수 있을까.
    //간단한 방법 ->  1부터 n까지 다 있는지 없는지 찾아보기. 반복문을 매우 많이 수행해야함.
    //배열의 인덱스 사용한 방법. 모두 오름차순으로 정렬시킨다음에 아니다.
    // 새로운 배열을 하나 만들고 o x를 한다. 해당 배열의 인덱스에해당하는 찾는 용도의 배열을 만들면
    // 한번만 쓱 훑어도 뭐가 없는지 알수 있다. 모두 0으로 초기화하고 여전히 0인 부분이 정답이다.
    //하지만 배열을 하나 더 만들어야해서 메모리 사용에 있어서 비효율 적일까..

    int K = 0;
    int sheetArr[SIZE] = { 0, }; // n개 짜리 표를 만든다. -> 실패! SIZE 짜리를 만든다. n이
    //그리고 모두 0으로 초기화한다.
    // partArr[]에는 무작위 숫자들이 n-1개가 있고, 이 숫자들의 범위는 1에서 n이다.
    // 0번째부터 쭉 그 값을 훑으면서 그 값에 해당하는 곳에 1을 넣는다. sheetArr[partArr[i]] 에 1을 넣는다.

    for(int i=0; i < lengthOfPartArr; i++){
        sheetArr[partArr[i]] = 1;
    }

    for(int i=1; i <= n ; i++){ //실제 예시의 수들은 1부터 n까지의 범위 이므로 0부터로 쓰지 않도록 주의.
        if( sheetArr[i] == 0 )
        {
            K = i;
            break; //더이상의 불필요한 반복을 끝내기 위해서.
        }
    }

    printf("K = %d\n", K);

    return 0;
}
