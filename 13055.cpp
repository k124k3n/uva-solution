#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll n; cin >> n;
    stack<string> dream;
    while(n--){
        string q; cin >> q;
        if(q == "Sleep"){
            string p; cin >> p;
            dream.push(p);
        }

        else if(q == "Kick" && !dream.empty()) dream.pop();

        else if(q == "Test"){
            if(dream.empty()) cout << "Not in a dream\n";
            else cout << dream.top() << "\n";
        }
    }
    return 0;
}