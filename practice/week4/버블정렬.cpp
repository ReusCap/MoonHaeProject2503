#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <iostream> // C++ 스타일 입출력을 위한 헤더파일 
using namespace std;    // std:: 생략 위해 사용

// 버블정렬 함수
// 인접한 두 값을 비교해 나가며 큰 값을 오른쪽으로 밀어내는 방식
// 버블정렬은 오른쪽부터 채워나가게 된다. 
void bubbleSort(int data[], int n){
    // 총 n번 반복
    for(int i=0; i < n; i++)
    {   
        // 만약 교환이 한번도 안일어나면 정렬되었단 뜻
        int negativecount = 0;
        // 마지막 i범위는 정렬 되었으니 그 전 부분만 비교
        for (int j=0; j < n-1-i; j++){
            if(data[j] > data[j+1]){
                // 두 값을 교환한다. tmp로 넣어두고 교환 후 tmp값 다시 넣기 
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
                negativecount++;
            }
        }
        // count가 0이면 정렬 되었단 뜻이니 break하도록 한다. (실제연산량 줄이기)
        if (negativecount == 0){
            break;
        }
    }
} 

// 메인함수
int main()
{   
    // 데이터 개수 n변수 선언
    int n;
    // 동적 배열 가리킬 int형 포인터 선언 
    int* data;

    // 데이터 개수 n 입력받기
    scanf("%d", &n);
    // n개의 동적 배열 생성
    data = new int[n];

    // n개만큼 배열에 입력받는다.
    for (int i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }

    // 버블정렬 함수 실행행
    bubbleSort(data, n);

    // 1칸씩 공백으로 구분하여 출력
    for (int i=0; i<n; i++){
        if (i>0){
            printf(" ");
        }
        printf("%d", data[i]);
    }

    // 동적 메모리 해제
    delete[] data;
    
    return 0;
}