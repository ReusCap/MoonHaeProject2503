#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <vector>   // 벡터 사용을 위한 헤더파일
using namespace std;    // std:: 생략 위해

// 학생과 악당 싸워서 승 패 판단 함수
// 앞의 인덱스부터 진행해서 먼저 이기는 쪽을 이기는 것으로 판단
// 학생이 이길 경우 true를, 악당이 이길 경우 false를 반환
bool studentsWin(int n, vector<int> students, vector<int> villians){
    // n만큼 for문 돌린다.
    for(int i = 0; i< n; i++){
        if(students[i] > villians[i]){
            // 학생이 이기는 것 발견하자마자 true반환하며 함수 나감
            return true;
        }
        else if (students[i] < villians[i]){
            // 악당이 이기는 것 발견하자마자 false반환하며 함수 나감
            return false;
        }
    }
    // 만약 모두 무승부라면 학생쪽이 승리하는 것으로 판단해서 true반환
    return true;
}

// 훈련해서 모든 학생 전투력 1씩 올리는 함수
vector<int> training(vector<int> students){
    // 전체 벡터 인덱스에 for문 돌림
    for (int i = 0; i < students.size(); i++) {
        students[i] += 1;   // 각 학생의 전투력 1 증가
    }
    // 1씩 강해진 학생 벡터 반환
    return students;
}

// 메인함수
int main()
{    
    // n : 전체 쌍의 수 
    int n;
    // 입력받기
    scanf("%d", &n);

    // 학생 전투력 벡터
    vector<int> students(n);
    // 학생 전투력 입력받음
    for (int i = 0; i<n; i++){
        scanf("%d", &students[i]);
    }

    // 악당 전투력 벡터
    vector<int> villains(n);
    // 악당 전투력 입력받음
    for (int i = 0; i<n; i++){
        scanf("%d", &villains[i]);
    }

    // 훈련 일 수 0 초기화
    int days = 0;
    // while문으로 studentsWin함수 반환값이 true가 될 때까지 돌린다.
    // true반환값이라는 건 학생들이 결국 이긴다는 뜻
    while (!studentsWin(n, students, villains)) {
        students = training(students);  // 모든 학생 전투력 1씩 증가
        days += 1;  // 훈련 일수 증가
    }

    // 최종 훈련 일 수 출력
    printf("%d\n", days);

    return 0;
}