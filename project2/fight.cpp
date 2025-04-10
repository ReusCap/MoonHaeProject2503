#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <vector>   // 벡터 사용을 위한 헤더파일
using namespace std;    // std:: 생략 위해

// 학생과 악당 싸워서 승 패 판단 함수
bool studentsWin(int n, vector<int> students, vector<int> villians){
    for(int i = 0; i< n; i++){
        if(students[i] > villians[i]){
            return true;
        }
        else if (students[i] < villians[i]){
            return false;
        }
    }
    return true;
}

// 훈련해서 전투력 올리는 함수
vector<int> training(vector<int> students){
    for (int i = 0; i < students.size(); i++) {
        students[i] += 1;
    }
    return students;
}

// 메인함수
int main()
{    
    // n : 전체 쌍의 수 
    int n;
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

    // 훈련 날짜 0 초기화
    int days = 0;
    while (!studentsWin(n, students, villains)) {
        students = training(students);
        days += 1;
    }

    printf("%d\n", days);

    return 0;
}