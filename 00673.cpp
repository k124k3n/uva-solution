#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll n; cin >> n;
    cin.ignore(1000, '\n');
    for(ll i = 0; i < n; i++){
        stack<char> q;
        string str;
        getline(cin, str);
        bool found = true;

        for(ll j = 0; str[j]; j++){
            if(str[j] == '[' || str[j] == '(') q.push(str[j]);

            else if(str[j] == ']'){
                if(q.empty() || q.top() != '['){
                    found = false;
                    
                    break;
                }
                q.pop();
            }

            else if(str[j] == ')'){
                if(q.empty() || q.top() != '('){
                    found = false;
                    
                    break;
                }
                q.pop();
            }
            
        }

        if(found && q.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}