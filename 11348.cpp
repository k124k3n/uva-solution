#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << fixed << setprecision(6);
    ll k; cin >> k;
    ll cs = 0;
    while(k--){
        cout << "Case " << ++cs << ": ";
        ll n; cin >> n;
        unordered_set<ll> hi[n];
        unordered_map<ll, ll> f;
        ll sumu = 0;
        for(ll i = 0; i < n; i++){
            
            ll m; cin >> m;
            while(m--){
                ll k; cin >> k;
                hi[i].insert(k);
            }

            for(auto x: hi[i]){
                ++f[x];
            }

            
        }

        vector<ll> res;

        for(ll i = 0; i < n; i++){
            ll sum = 0;
            for(auto x: hi[i]){
                if(f[x]==1){
                    ++sum;
                    ++sumu;
                }
            }

            res.push_back(sum);
        }

        for(ll i = 0; i < res.size(); i++){
            if(sumu==0) cout << (double) 0/1.0 << "%";
            else cout << (double) res[i]*100/sumu << "%";
            if(i!=(res.size()-1)) cout << " ";
        }
        
        cout << "\n";
    }
    return 0;
}