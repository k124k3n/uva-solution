#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n,m,reg[501][501];

ll ubver(ll i, ll j, ll val){
    ll l = i-1, r = i+min(m-j-1, n-i-1)+1;

    // cout << i << " " << j << "\n";
    // cout << l << " " << r << "\n";
    while(l < r){
        ll mid = l + (r-l)/2;

        if(reg[mid][mid+j-i] <= val){
            l = mid+1;
        }

        else r = mid;
    }

    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    while(cin >> n >> m && n){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                cin >> reg[i][j];
            }
        }

        ll t; cin >> t;

        while(t--){
            ll Max = 0;
            ll x,y; cin >> x >> y;
            for(ll i = 0; i < n; i++){
                // cout << i << "\n";
                ll lo = lower_bound(reg[i], reg[i]+m, x) - reg[i];
                ll tr = ubver(i, lo, y) - i;
                // cout << tr << "\n";
                Max = max(Max, tr);
            }

            cout << Max << "\n";
        }
        cout << "-\n";
    }
    return 0;
}