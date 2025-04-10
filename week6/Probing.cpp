#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <vector>   // 벡터 사용을 위한 헤더파일
using namespace std;    // std:: 생략 위해

// 티켓테이블 클래스 
class TicketTable{
// public (접근지정자) 클래스 외부 접근 가능
public:
    vector<bool> used;  // 해당 인덱스의 티켓이 사용되었는지 여부를 저장
    int length; // 전체 티켓 수

    // 생성자: 전체 티켓 수만큼 used 배열 초기화 (모두 false = 사용되지 않음)
    TicketTable(int length) {
        this->length = length;
        this->used.assign(length, false);   // false로 초기화
    }

    // 사용자의 회원 번호로 지급받게 될 행운권 번호를 계산하는 함수
    int findEmptyIndexByUserId(int userId) {
        // 기본 티켓 인덱스는 userId를 length로 나눈 나머지 값
        int index = userId % length;    // 가장 초기에 시도 할 티켓 번호
        while(this -> isEmpty(index) == true){  // 사용된 티켓 번호라면 건너 뛴다.
            index = (index +1)%length;  // 다음 번호를 조사해나간다.
        }
        return index;   // 사용되지 않은 인덱스를 찾아서 반환한다.
    }

    // 해당 행운권 번호가 이미 사용중인지 여부를 반환하는 메소드
    bool isEmpty(int ticketIndex) {
        return this->used[ticketIndex]; // 사용 여부 <==> used[ticketIndex]
    }

    // 티켓 사용 여부를 갱신하기 위한 메소드
    void setUsed(int index, bool status){
        // 사용한 인덱스를 보통 true로 바꾸는 역할
        this->used[index] = status;
    }
};

// n개의 티켓 중에서, m명의 사용자에게 티켓 번호를 부여하는 함수
// 입력: 티켓 개수 n, 고객객 수 m, 사용자 ID 리스트
// 출력: 사용자에게 부여된 티켓 번호 리스트
vector<int> getTicketNumbers(int n, int m, const vector<int>& ids){
    // 티켓 번호 저장 vector
    vector<int> tickets;
    // Tickettable타입 객체 생성
    TicketTable table = TicketTable(n);

    // 고객 수만큼 loop
    for(int i = 0; i<m; i++){
        int userId = ids[i];    // 사용자 id
        int ticketIndex = table.findEmptyIndexByUserId(userId); // 해당 사용자에게 배정할 티켓 인덱스 계산
        tickets.push_back(ticketIndex); // 결과 벡터에 추가
        table.setUsed(ticketIndex, true);   // 티켓을 사용 상태로 갱신
    }
    // 티켓 번호 저장 vector 반환
    return tickets;
}

// 메인함수
int main()
{    
    // n : 전체 티켓의 수
    // m : 요청 고객의 수
    int n,m;
    scanf("%d %d", &n, &m);

    // 고객 id리스트 벡터
    vector<int> ids(m);
    // id입력받음
    for (int i = 0; i<m; i++){
        scanf("%d", &ids[i]);
    }

    // 티켓 번호 계산
    // getTicketNumbers함수 사용용
    vector<int> tickets = getTicketNumbers(n,m,ids);
    for (int i = 0; i<tickets.size(); i++){
        printf("%d\n", tickets[i]); // 결과 출력
    }
}