#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
using namespace std;    // std:: 생략 위해

const int MAX_SEAT_NUMBER = 1000;   // 좌석 최대 개수
const int MAX_COLOR_NUMBER = 100;   // 색깔 최대 개수 

// 좌석들을 한 번 색칠하는 이벤트에 대한 정보 담는 클래스
class SudokuBoard{
// public (접근지정자) 클래스 외부 접근 가능
public:
    // 색칠 범위 왼쪽, 오른쪽, 색깔 번호
    int left;   
    int right;
    int color;

    // 기본 생성자
    SudokuBoard() {}
    
    // 매개변수 받는 생성자
    SudokuBoard(int left, int right, int color){
        // 각각 입력받아 초기화 시켜줌.
        this->left =left;
        this->right = right;
        this->color = color;
    }
};

// 좌석 배열에서 색깔별 등장 횟수를 테이블에 저장
void fillFrequencyTable(int data[], int n, int table[]){
    // table을 0으로 초기화. 
    for (int i=0; i< MAX_COLOR_NUMBER; i++){
        table[i] = 0;
    }
    // table에 나타난 횟수만큼 증가.
    for (int i=0; i<n; i++){
        int color = data[i];
        table[color] +=1;
    }
} 
// 주어진 색칠 이벤트들을 적용한 후, 가장 많이, 가장 적게 사용된 색깔 번호를 출력
void solve(int n, int m, const SudokuBoard* paintings){
    // 좌석 배열 설정 및 초기화
    int* seats = new int[n];
    
    // 처음 좌석은 모두 0으로 칠해져 있다. 
    for (int i = 0; i< n; i++){
        seats[i] = 0;
    }

    // 색칠 이벤트 순차적으로 적용
    for (int i=0; i<m;  i++){
        const SudokuBoard &p = paintings[i];

        // 각 이벤트마다 해당 구간을 지정한 색으로 덮어 칠함
        for (int j= p.left; j <= p.right; j++){
            seats[j] = p.color;
        }
    }

    // 색깔 빈도수 저장용 배열 동적 할당
    int * table = new int[MAX_COLOR_NUMBER];
    fillFrequencyTable(seats, n, table);    // 색 빈도 계산

    // min, max의 초기값 설정
    int minColor = seats[0];    // 가장 많이 등장한 색깔
    int maxColor = seats[0];    // 가장 적게 등장한 색깔 

    for (int color = 0; color < MAX_COLOR_NUMBER; color +=1){
        if(table[color] == 0){  // 한번도 등장하지 않은 색깔 
            continue;
        }

        // 한번 이상 등장한 색깔에 대하여 
        if(table[minColor] > table[color]){ // 가장 적게 등장한 색이 아직 없거나, color가 더 적게 등장한 경우
            minColor = color;
        }
        if(table[maxColor] < table[color]){ // 가장 많이 등장한 색이 아직 없거나, color가 더 많이 등장한 경우
            maxColor = color;
        }
    }
    // 결과들 출력
    printf("%d\n", maxColor);
    printf("%d\n", minColor);

    // table과 seats 동적 메모리 해제
    delete[] table;
    delete[] seats;
} 

// 메인함수
int main()
{   
    // 좌석 수 N과 색칠 방법 수 M
    int n, m;

    // 입력받기
    scanf("%d %d", &n, &m);
    
    // 색칠 이벤트 저장할 배열 동적 할당
    SudokuBoard* paintings = new SudokuBoard[m];

    // 색칠 이벤트 입력받기
    for (int i=0; i<m; i++)
    {
        scanf("%d", &paintings[i].left);
        scanf("%d", &paintings[i].right);
        scanf("%d", &paintings[i].color);

        // 좌석의 번호와 인덱스 차를 맞추기 위해 1을 빼준다. 
        paintings[i].left -= 1;
        paintings[i].right -= 1;
    }

    // 문제의 정답을 구한다.
    solve(n,m,paintings);

    // 동적 메모리 해제
    delete[] paintings;
    return 0;
}