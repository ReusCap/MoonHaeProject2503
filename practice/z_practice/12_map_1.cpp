#include<iostream>
#include<set>
#include<map>

using namespace std;

int main(){
    map<int, int> m;

    m.insert(make_pair(1,1));
    m[2]=2;
    m[3]=3;
    m.erase(m[2]);

    for (auto it = m.begin(); it != m.end(); it++){
        cout << it->first << ' ' << it->second <<endl; 
    }
    return 0;
}