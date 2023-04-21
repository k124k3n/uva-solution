#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    for(ll z = 1; z <= t; z++){
        cout << "Case " << z << ": ";
        ll m, s, a[4]; cin >> m >> s;
        bool isTrig[4] = {false};
        ll now = 1;
        bool en[4], tres[4];
        for(ll i = 0; i < 4; i++) cin >> a[i];
        ll c,k; cin >> c >> k;

        for(ll i = 0; i < 4; i++){ // enabled
            ll hi = c%2;
            en[i] = hi;
            c /= 2;
        }

        for(ll i = 0; i < 4; i++){ // threshold
            ll hi = c%2;
            tres[i] = hi;
            c /= 2;
        }

        for(ll i = 0; i < k; i++){
            ll p,q; cin >> p >> q;
            ll hm = now + (p-1); // end duration
            ll ub = (hm-s)/m; // upperbound find(X) need to fullfill s + mx = hm
            ll rl = s + (m*ub); // first designed number
            // cout << now << " " << hm << "\n";
            
            if(rl > hm || rl < s || rl < now){ // now <= rl <= hm
                now += p;
                continue;
            }
            
            for(ll j = 0; j < 4; j++){
                if(tres[j] == 0 && q < a[j]){ // down
                    isTrig[j] = true;
                }

                if(tres[j] == 1 && q > a[j]){ // up
                    isTrig[j] = true;
                }
            }

            now += p;
        }

        for(ll i = 0; i < 4; i++){
            if(en[i] && isTrig[i]) cout << "yes";
            else cout << "no";
            if(i!=3) cout << " ";
        }

        cout << "\n";
    }
    return 0;
}