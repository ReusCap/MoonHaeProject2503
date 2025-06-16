#include <iostream>
using namespace std;
// 3주차 오름차순인지 판단하는는 문제
int main() {
    int n;
    cin >> n;

    int* data = new int[n];
    for (int i=0;i<n;i++){
        cin>>data[i];
    }
    // 결과 반환 변수
    bool ordered = true;

    for (int i=0; i<n-1; i++){
        if(data[i]> data[i+1]){
            ordered = false;
            break;
        }
    }

    if (ordered){
        cout << "YES";
    }
    else{
        cout <<"NO";
    }
    delete[] data;
    return 0;
}
