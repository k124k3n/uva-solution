#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    while(cin >> n && n){
        ll sz = log2(n) + 1;

        ll a = 0, b = 0;
        ll cnt = 0;

        for(ll i = 0; i < sz; i++){
            ll res = n & (1 << i);

            if(res != 0){
                ++cnt;

                if(cnt%2) a |= (1 << i);
                else b |= (1 << i);
            }
        }

        cout << a << " " << b << "\n";

    }
    return 0;
}