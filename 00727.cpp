#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<string, ll> prio({
    {"+", 0},
    {"-", 0},
    {"*", 1},
    {"/", 1},
});

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string temp;
    ll t; cin >> t;
    cin.ignore(1000, '\n');
    getline(cin, temp);
    
    stack<string> q;
    

    ll sp = 0;
    while(getline(cin, temp)){
        if(temp.empty()){
            while(!q.empty()){
                cout << q.top();
                q.pop();
            }
            cout << "\n\n";
        }
        if(isdigit(temp[0])){
            cout << temp;
        }

        else if(temp == "("){
            q.push(temp);
        }

        else if(temp == ")"){
            while(q.top() != "("){
                cout << q.top();
                q.pop();
            }
            q.pop();
        }
        
        else{
            while(!q.empty() && q.top() != "(" && prio[q.top()] >= prio[temp]){
                cout << q.top();
                q.pop();
            }
            q.push(temp);
        }
    }

    while(!q.empty()){
        cout << q.top();
        q.pop();
    }
    cout << "\n";
    return 0;
}