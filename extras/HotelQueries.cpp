#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ll n,m; cin >> n >> m;
    set<pair<ll,ll>> hi;
    for(ll i = 0; i < n; i++){
        ll c; cin >> c;
        hi.insert({c, i+1});
    }

    for(ll i = 0; i < m; i++){
        ll c; cin >> c;
        pair<ll,ll> pos = *hi.lower_bound({c,0});
        

        cout << ((hi.find(pos)==hi.end())?(0):(pos.second)) << " ";

        // for(auto &[x,y]: hi){
        //     cout << x << " " << y << "\n";
        // }
        
        if(hi.find(pos)!=hi.end())hi.erase(pos);

    } cout << "\n";
    return 0;
}