#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;

    while(cin >> n && n){
        vector<ll> adj[n];
        vector<ll> color(n, 999);
        ll k; cin >> k;
        while(k--){
            ll a,b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        queue<ll> q; q.push(0);
        color[0] = 0;
        bool bip = true;
        while(!q.empty() && bip){
            ll now = q.front(); q.pop();

            for(auto x: adj[now]){
                if(color[x]==999){ // UNVISITED
                    color[x] = 1 - color[now];
                    q.push(x);
                }
                else if(color[x]==color[now]){
                    bip = false;
                    break;
                }
            }
        }

        if(bip) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}