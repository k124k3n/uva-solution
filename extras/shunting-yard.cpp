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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    stack<string> q;
    string str; getline(cin, str);
    stringstream ss(str); string temp;

    while(ss >> temp){

        if(isdigit(temp[0])){
            cout << temp << " ";
        }

        else if(temp == "("){
            q.push(temp);
        }

        else if(temp == ")"){
            while(q.top() != "("){
                cout << q.top() << " ";
                q.pop();
            }
            q.pop();
        }
        
        else{
            while(!q.empty() && q.top() != "(" && prio[q.top()] >= prio[temp]){
                cout << q.top() << " ";
                q.pop();
            }
            q.push(temp);
        }
    }

    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << "\n";
    
    return 0;
}