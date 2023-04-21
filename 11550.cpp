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
        ll n,m; cin >> n >> m; 

        if(m==0){
            cout << "Yes\n";
            continue;
        }

        ll col[m] = {0};
        unordered_map<ll, bool> state;
        bool found = true;

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                ll temp; cin >> temp;
                col[j] |= (temp << i);
            }
        }

        for(ll i = 0; i < m; i++){
            if(__builtin_popcount(col[i]) != 2 || state[col[i]]){
                found = false;
                // break;
            }

            state[col[i]] = true;
        }

        if(found) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}