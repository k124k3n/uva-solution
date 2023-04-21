#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;
        ll sum[10] = {0};

        for(ll i = 1; i <= n; i++){
            ll temp = i;

            while(temp > 0){
                ll mod = temp%10;
                ++sum[mod];
                temp /= 10;
            }
        }

        for(ll i = 0; i < 10; i++){
            cout << sum[i];
            if(i!=9) cout << " ";
        } cout << "\n";

    }

    return 0;
}