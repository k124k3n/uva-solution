#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> adj[205];
vector<ll> color(205, 999);


ll check(ll k){
    ll ans[2] = {0};
    queue<ll> q; q.push(k);
    color[k] = 0; ++ans[0];
    bool bip = true;
    while(!q.empty() && bip){
        ll now = q.front(); q.pop();
        for(auto x: adj[now]){
            if(color[x]==999){
                color[x] = 1 - color[now];
                ++ans[color[x]];
                q.push(x);
            }

            else if(color[x]==color[now]){
                bip = false;
                break;
            }
        }
    }

    if(bip) return max(ans[0], ans[1]);
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll res = 0;
        // reset
        for(ll i = 1; i <= n; i++){
            adj[i].clear();
            color[i] = 999;
        }

        for(ll i = 1; i <= n; i++){
            ll k; cin >> k;
            while(k--){
                ll temp; cin >> temp;
                adj[i].push_back(temp);
                adj[temp].push_back(i);
            }
        }

        for(ll i = 1; i <= n; i++){
            if(color[i] == 999) res += check(i);
        }

        cout << res << "\n";
    }
    return 0;
}