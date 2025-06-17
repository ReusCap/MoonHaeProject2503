#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <iostream> // C++ 스타일 입출력을 위한 헤더파일 
using namespace std;    // std:: 생략 위해 사용

bool isConsecutive(int data[], int n){
    int max_data = data[0];
    int min_data= data[0];

    // 어차피 서로 다른 수만 data에 입력되어 있으니 연속적인 수인지 판단하려면면
    // max-min = n-1 만 판단하면 됨
    for (int i=0; i<n; i++){
        // max보다 큰 수면 업데이트
        if(max_data < data[i])
            max_data = data[i];
        // min보다 작은 수면 min에 업데이트
        if(min_data > data[i])  // else를 넣으면 안 됨. 
            min_data = data[i];
    }
    // 만약 max와 min의 차이가 n-1이면 true반환, 아니면 false반환
    if (max_data- min_data == n-1){
        return true;
    }else {
        return false;
    }
}

// 메인함수
int main()
{   
    // 에피소드 수 n변수 선언
    int n;
    // 동적 배열 가리킬 int형 포인터 선언 
    int* data;

    // 에피소드 수 n 입력받기
    scanf("%d", &n);
    // n개의 동적 배열 생성
    data = new int[n];

    // n개만큼 배열에 입력받는다.
    for (int i=0; i<n; i++)
    {   
        // 입력 조건에서 모든 번호들은 서로 다르다고 한다.
        scanf("%d", &data[i]);
    }

    // isConsecutive 함수 사용용
    bool result = isConsecutive(data, n);

    // result값에 따라 결과 출력
    if(result){
        printf("YES");
    }else{
        printf("NO");
    }

    // 동적 메모리 해제
    delete[] data;
    
    return 0;
}