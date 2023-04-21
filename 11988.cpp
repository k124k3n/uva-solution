#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;

    while(cin >> str){
        stack<char> b;
        deque<char> temp;
        deque<char> hi;

        for(ll i = 0; str[i]; i++){
            if(str[i] == '['){
                b.push('[');
                while(!temp.empty()){
                    hi.push_front(temp.back());
                    temp.pop_back();
                }
            }

            else if(str[i] == ']'){
                while(!temp.empty()){
                    hi.push_front(temp.back());
                    temp.pop_back();
                }
                b = {};
            }

            else{
                if(b.empty()) hi.push_back(str[i]);
                else temp.push_back(str[i]);
            }
        }

        while(!temp.empty()){
            hi.push_front(temp.back());
            temp.pop_back();
        }
                
        

        for(auto x: hi){
            cout << x;
        } cout << "\n";
    }
    return 0;
}