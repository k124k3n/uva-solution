#include <bits/stdc++.h>
using namespace std;

#define ll long long

unordered_map<ll, vector<ll>> cs;

unordered_map<char, ll> dat({
    {'A', 0},
    {'C', 1},
    {'G', 2},
    {'T', 3},
});

ll freq[4];

ll inv(string a){
    ll sum = 0;
    for(ll i = 0; i < 4; i++) freq[i] = 0;

    for(ll i = a.length()-1; i >= 0; i--){
        for(ll j = dat[a[i]]; j <= 3; j++) ++freq[j];

        if(a[i] != 'A'){
            sum += freq[dat[a[i]]-1];
        }
    }

    // cout << sum << " " << a << "\n";
    return sum;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;
    while(t--){
        cs.clear();
        vector<string> hi;
        ll n,m; cin >> n >> m;
        ll l = LLONG_MAX;
        ll r = LLONG_MIN;
        string temp;

        for(ll i = 0; i < m; i++){
            cin >> temp;
            hi.push_back(temp);
            ll res = inv(temp);
            cs[res].push_back(i);
            l = min(l, res);
            r = max(r, res);
        }

        for(ll i = l; i <= r; i++){
            for(auto x: cs[i]){
                cout << hi[x] << "\n";
            }
            
        }

        if(t!=0) cout << "\n";
    }
    return 0;
}