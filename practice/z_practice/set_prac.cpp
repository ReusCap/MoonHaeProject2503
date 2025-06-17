#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int> s;

    int n;
    cin >> n;

    for (int i =0; i <n; i++){
        int x;
        cin >> x;

        if (s.count(x)>0){
            cout <<"DUPLICATED"<< endl;
        }
        else{
            s.insert(x);
            cout <<"OK" <<endl;
        }
    }
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }


    return 0;
}