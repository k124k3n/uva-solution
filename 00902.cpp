#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    while(cin >> n){
        string str; cin >> str;
        unordered_map<string, ll> f;
        ll Max = LLONG_MIN; string res;
        for(ll i = 0; i < str.length()-n; i++){

            if(++f[str.substr(i, n)] > Max){
                Max= f[str.substr(i, n)];
                res = str.substr(i, n);
            }

        }

        cout << res << "\n";

    }
    return 0;
}