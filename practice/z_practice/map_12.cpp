#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> m;
    int maxpoll = 0;
    for (int i=0; i<N; i++){
        string s;
        cin >> s;
        m[s]++;
        int k = m[s];
        if(m[s]>maxpoll){
            maxpoll=k;
        }
    }
    cout<< maxpoll << endl;
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second == maxpoll){
            cout<< it->first << ' ';
        }
    }    
    auto it = m.find("apple");
    if (it != m.end()) {
        cout << "찾음: " << it->second << '\n';
    }   
}
