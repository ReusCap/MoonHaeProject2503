#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    map<string, int> m;
    int maxpoll=0;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        m[s]++;
        if (m[s]>maxpoll){
            maxpoll=m[s];
        }
    }
    cout << maxpoll << endl;
    for(auto it=m.begin(); it != m.end(); it++){
        if(it -> second == maxpoll){
            cout << it -> first << " ";
        }
    }
    return 0;
}