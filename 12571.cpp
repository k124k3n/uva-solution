#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;
    
    ll sz = 9;
    // for(ll i = 0; i < 300; i++){
    //     for(ll j = i; j <= 1024; j++){
    //         dp[i][j] = i&j;
    //     }
    // }

    while(t--){
        ll n,q; cin >> n >> q;
        ll Max[240] = {0};
        
        unordered_set<ll> arr;

        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            arr.insert(temp & ((1 << sz)-1));
        }

        for(ll i = 0; i < 230; i++){
            for(auto j: arr){
                Max[i] = max(Max[i], (i&j));
            }
        }
        
        // for(auto j: arr){
        //     cout << j << " ";
        // } cout << "\n";

        for(ll i = 0; i < q; i++){
            ll a; cin >> a;
            cout << Max[a] << "\n";
        }
    }

    return 0;
}