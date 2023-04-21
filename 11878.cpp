#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll a,b; char o, e; string res;
    ll sum = 0;
    while(cin >> a >> o >> b >> e >> res){
        ll final;
        if(res == "?") continue;

        if(o == '+') final = a+b;
        if(o == '-') final = a-b;
        
        if(final==stoi(res)) ++sum;
    }

    cout << sum << "\n";
    return 0;
}