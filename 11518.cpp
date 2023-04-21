#include <bits/stdc++.h>
using namespace std;

#define ll long long


vector<ll> adj[10002];
bool visited[10002];

ll dfs(ll k){
    if(visited[k]) return 0;
    visited[k] = true;
    ll sum = 1;
    for(auto x: adj[k]){
        sum += dfs(x);
    }
    return sum;
}

void rst(ll k){
    if(!visited[k]) return;
    visited[k] = false;
    
    for(auto x: adj[k]){
        rst(x);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t; cin >> t;

    while(t--){
        ll total = 0;
        for(ll i = 0; i < 10002; i++){
            adj[i].clear();
            visited[i] = false;
        }
        ll n,m,l; cin >> n >> m >> l;
        while(m--){
            ll x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        while(l--){
            ll k; cin >> k;
            total += dfs(k);
        }

        cout << total << "\n";
        
    }

    return 0;
}