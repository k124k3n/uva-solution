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
        ll p, c; cin >> p >> c;

        if(p==0){
            cout << "0 0\n";
            continue;
        }
        
        ll P[p], C[c];
        ll max_val = LLONG_MAX;
        ll maks = LLONG_MIN;
        ll val = -1;
        unordered_set<ll> hi;
        for(ll i = 0; i < p; i++){
            cin >> P[i];
            hi.insert(P[i]);
        }

        for(ll i = 0; i < c; i++){
            cin >> C[i];
            hi.insert(C[i]);
            maks = max(maks, C[i]);
        }

        if(c==0 || (p==0&&c==0)){
            cout << maks << " " << 0 << "\n";
            continue;
        }

        
        sort(P, P+p); sort(C, C+c);

        for(auto x: hi){
            ll lop = p - (upper_bound(P, P+p, x) - P); // jlh elemen yg > x di P
            
            ll loc = (upper_bound(C, C+c, x-1) - C) ; // jlh elemen yg < x di C
            ll sum = (lop+loc);

            // cout << x << " " << lop << " " << loc << "\n";
            if(sum < max_val){
                max_val = sum;
                val = x;
            }

            else if(sum == max_val){
                val = min(x, val);
            }
        }

        cout << val << " " << max_val << "\n";
        
    }

    return 0;
}