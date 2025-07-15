#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    // N은 곡의 개수, C는 크로스페이드 적용 시간 초
    int N, C;
    cin >> N >> C;

    int crosscnt = N-1;
    int crosstime = (N-1)*C;

    int M=0;
    int SS=0;
    for(int i=0; i<N; i++){
        char *s = new char[5];
        cin >> s;
        if (s[0]!=0){
            M+=(s[0]-48)*60;
        }
        if (s[2]!=0 && s[3]!=0){
            SS+=(s[2]-48)*10 + s[3]-48;
        }
        else if(s[2]!=0 && s[3]==0){
            SS+=(s[2]-48)*10;
        }
        else if(s[2]==0 && s[3]!=0){
            SS+=s[3]-48;
        }

    }
    int answer = M+SS-crosstime;
    if (answer <= 0){
        cout << "00:00:00" << endl;
        return 0;
    }
    int hh=(answer/3600)%24;
    int mm=(answer/60)%60;
    int ss=(answer%60);

    string s1 = to_string(hh);
    string s2 = to_string(mm);
    string s3 = to_string(ss);
    vector<string> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);

    for(int i=0; i<3; i++){
        if(v[i].length()<2){
            v[i]= "0"+v[i];
        }
    }
    cout << v[0] << ":" << v[1] << ":" << v[2] << endl;
    
    return 0;
    
    
    
}