#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll m,n;

    while(cin >> m >> n && m){
        unordered_map<ll, ll> f;

        ll A[m];
        ll sum = 0;
        for(ll i = 0; i < m; i++){
            cin >> A[i];
            ++f[A[i]];
        }

        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            if(f[temp]){
                ++sum;
            }
        }

        cout << sum << "\n";
    }
    return 0;
}