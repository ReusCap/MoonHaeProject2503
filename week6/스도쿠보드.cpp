#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
using namespace std;    // std:: 생략 위해

const int MAX_ROW = 9;   // 스도쿠 행 크기 상수
const int MAX_COL = 9;   // 스도쿠 열 크기 상수

// 스도쿠 보드 클래스
class SudokuBoard{
// public (접근지정자) 클래스 외부 접근 가능
public:
    // 칸의 번호로 행의 번호를 계산하는 메소드
    int getRowByIndex(int index) {
        // 1을 차감해서 0부터 시작해 규칙성 파악
        // 칸의 번호에 대해 마디를 가지고 증가하므로 몫으로 계산 가능
        return (index-1) / 9 +1;
    }

    // 칸의 번호로 열의 번호를 계산하는 메소드
    int getColByIndex(int index) {
        // 칸의 번호에 대해 규칙적으로 순환하므로 나머지로 계산할 수 있다.
        return (index - 1) % 9 +1;
    }   

    // 칸의 번호로 그룹 번호를 계산하는 메소드
    int getGroupByIndex(int index){
        // index로 행과 열 번호 계산산
        int r = getRowByIndex(index);
        int c = getColByIndex(index);
        // getGroupByPosition함수 실행한 값 리턴 
        return getGroupByPosition(r,c);
    }

    // 칸의 위치(행, 열)로 그룹 번호를 계산하는 메소드
    int getGroupByPosition(int row, int column){
        // 행의 번호를 통해, 해당 행의 존재하는 그룹들 중 가장 왼쪽 그룹의 번호를 알 수 있다. 
        // 1, 4, 7 나오게 만듦
        int left = ((row-1)/3)*3+1;
        // 해당 번호를 통해, 해당 행에 존재하는 그룹들 중 몇 번째 그룹에 속하는지 알 수 있다.
        // 0,1,2 나오게 만듦.
        int offset = ((column -1)/3);
        // 그래서 left와 offset 더한 값 리턴 
        return left + offset;
    }

    // 칸의 위치 (행, 열)로 칸의 번호를 계산하는 메소드
    int getIndexByPosition(int row, int column){
        // 행과 열 번호를 알면 반대로 인덱스도 쉽게 계산할 수 잇다. 
        return (row -1)*9 + (column -1) % 9 + 1;
    }    
};

// 좌석 배열에서 색깔별 등장 횟수를 테이블에 저장
void process(int caseIndex){
    // 인덱스 선언 후 입력 받기
    int index;
    scanf("%d", &index);

    // SudokuBoard 클래스 인스턴스 생성
    // 클래스 타입 변수 선언 + 기본 생성자로 초기화
    SudokuBoard board = SudokuBoard();

    // 칸의 번호로 행, 열, 그룹 번호를 계산한다.
    int row = board.getRowByIndex(index);
    int col = board.getColByIndex(index);
    int group = board.getGroupByIndex(index);

    // 출력 형식
    printf("Case #%d:\n", caseIndex);
    printf("%d %d %d\n", row, col, group);  

} 

// 메인함수
int main()
{   // 테스트 케이스 수
    int caseSize;
    // 입력받기
    scanf("%d", &caseSize);

    // 각 케이스 별로 실행
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++){
        // process함수 테스트 케이스별로 실행행
        process(caseIndex);
    }
    return 0;
}