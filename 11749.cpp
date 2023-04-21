#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool visited[502];
vector<pair<ll, ll>> adj[502];

vector<ll> dfs(ll k){
    if(visited[k]) return {0, 0};
    visited[k] = true;
    ll sum = 1;
    ll jal = 0;
    vector<ll> hi;
    for(auto &[x,c]: adj[k]){
        if(!visited[x]){
            vector<ll> res = dfs(x);
            jal += c;
            jal += res[1];
            sum += res[0];
        }
    }
    hi = {sum, jal};
    return hi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n,m;

    while(cin >> n >> m && n){
        ll MaxS = LLONG_MIN, MaxC = LLONG_MIN;
        for(ll i = 0; i < 502; i++){
            visited[i] = false;
            adj[i].clear();
        }

        while(m--){
            ll x, y, c; cin >> x >> y >> c;
            adj[x].emplace_back(y, c);
            adj[y].emplace_back(x, c);
        }

        for(ll i = 1; i <= n; i++){
            vector<ll> res = dfs(i);

            double av = (double)res[1]/res[0];
            if(av > MaxS){
                MaxC = res[0];
                MaxS = res[1];
            }

            else if(av == MaxS){
                MaxC = max(MaxC, res[0]);
            }
        }

        cout << MaxC << "\n";
    }
    return 0;
}