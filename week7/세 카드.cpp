#include <stdio.h>  // C 스타일 입출력을 위한 헤더
#include <vector>   // C++ 벡터 사용을 위한 헤더
#include <algorithm>    // 정렬 및 이진 탐색 함수 등을 위한 헤더

using namespace std;

// 중복을 포함해 세 카드의 합으로 만들 수 있는 당첨번호의 수를 계산하는 함수
vector<int> getPossibleTargets(int n, int m, int *cards, int *targets){
    // 만들 수 있는 당첨 번호들(최종 리턴하는 값)
    vector<int> possibleTargets;

    // 모든 카드를 오름차순으로 정렬한다. 바이너리 서치를 하기 위한 조건
    sort(cards, cards +n);

    // m개의 후보 당첨번호 수 만큼 for문
    for(int i=0; i< m; ++i)
    {
        int k =targets[i];  // 현재 확인 중인 후보 당첨번호 k
        bool possible = false;  // 세 카드로 k를 만들 수 있는지 여부 초기화

        // 첫 번째 카드 x를 선택하는 반복문
        for(int j=0; j<n; ++j)
        {
            int x=cards[j]; // 첫 번째 카드 x

            // 두 번째 카드 y를 선택 (중복 허용, 순서를 고정하여 중복 제거)
            for(int p=0; p<=j; p+=1)    // x, y 순서 중복 방지 위해 j까지 for문
            {
                int y = cards[p];   // 두 번째 카드 y를 선택한다.
                int z = k-(x+y);    // 세 번째 카드 z계산, k=(x + y)+ z가 되는 z를 계산한다.

                // 세 카드 합=k 만족시키는 세 번째 카드 z가 cards 배열에 존재하는지 확인 (이진 탐색)
                if(binary_search(cards, cards+n,z)==true)   // 시작위치, 끝위치, 찾을 값
                {   
                    // k = x+y+z가 가능한 <x,y,z>가 존재한다. 세 카드 합 k가능?
                    possible = true;
                    break;
                }
            }
            if (possible) { // 이미 가능한 조합을 찾았으므로 바깥 for문도 탈출
                break;
            }
        }
        // 세 카드의 합으로 k를 만들 수 있다면 해당 k 값을 결과 벡터에 추가
        if(possible){
            possibleTargets.push_back(k);
        }
    }

    // 가능한 당첨번호 오름차순으로 정렬하고 리턴
    sort(possibleTargets.begin(), possibleTargets.end());
    return possibleTargets;
}

int main(){
    int n;  // 카드의 수
    int m;  // 검사 할 후보 당첨번호의 수
    scanf("%d %d", &n, &m);
    
    int* cards = new int[n];    // 카드번호
    int* targets = new int[m];  // 당첨번호

    // 각 카드 정보를 입력받는다.
    for (int i=0; i<n; i++){
        scanf("%d", &cards[i]);
    }   

    // 각 후보 당첨번호를 입력받는다.
    for (int i=0; i<m; i++){
        scanf("%d", &targets[i]);
    }

    // answers 벡터에 가능한 당첨번호 배열 저장.
    // getPossibletargets함수 리턴값.
    vector<int> answers = getPossibleTargets(n,m,cards,targets);
    
    // 만약 실제로 만들 수 있는 당첨번호 없으면 NO출력
    // size=0인 경우
    if (answers.size()==0){
        printf("NO");
    }
    // 실제로 만들 수 있는 당첨번호 있는경우
    else{
        // answers벡터 크기만큼 for문 돌려서 공백을 두고 출력
        for(int i=0; i<answers.size(); i++)
        {   
            // 첫번째 수는 바로 출력하고, 다음 인덱스부터 공백 두고 출력
            if(i>0)
            {
                printf(" ");
            }
            printf("%d", answers[i]);
        }
    }
    // 동적 메모리 해제
    delete[] cards;
    delete[] targets;
}