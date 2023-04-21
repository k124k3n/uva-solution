#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n,m;

    while(cin >> n >> m){
        unordered_map<ll, vector<ll>> hi;
        for(ll i = 1; i <= n; i++){
            ll temp; cin >> temp;
            hi[temp].push_back(i);
        }

        for(ll i = 0; i < m; i++){
            ll k,v; cin >> k >> v;
            if(hi[v].size() < k){
                cout << 0 << "\n";
            }

            else{
                cout << hi[v][k-1] << "\n";
            }

        }

    }
    return 0;
}