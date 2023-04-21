#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string temp;

    unordered_map<char, bool> op({
        {'{', 1},
        {'(', 1},
        {'[', 1},
        {'<', 1},
    });

    map<char, string> cl({
        {'}', "{"},
        {')', "("},
        {']', "["},
        {'>', "<"},
    });

    string str;
    while(getline(cin, str)){
        ll res = 0;
        
        
        string h;
        bool found = true;
        stack<string> hi;
        deque<ll> itr;

        ll pos = 1;

        for(ll i = 0; str[i]; i++, pos++){ // pisah space
            if(str[i] == '(' && str[i+1] && str[i+1] == '*'){
                hi.push("(*");
                i++;
                continue;
            }

            if(op[str[i]]){
                hi.push(string(1, str[i]));
                continue;
            }

            if(str[i] == '*' && str[i+1] && str[i+1] == ')'){
                if(hi.empty() || hi.top() != "(*"){
                    found = false;
                    break;
                }

                
                hi.pop();
                i++;
                continue;
            }

            if(cl.find(str[i]) != cl.end()){
                if(hi.empty() || hi.top() != cl[str[i]]){
                    found = false;
                    break;
                }
                
                hi.pop();
                continue;
            }            
            
        }

        
        if(found && hi.empty()) cout << "YES\n";
        else cout << "NO " << pos << "\n";
    }
    return 0;
}