#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> g;
ll vis[20][20];
ll step = 0;
ll v[20][20];
ll sum = 0;
bool inf;

void dfs(ll x, ll y, ll sos){
    if(x<0||y<0||x==g.size()||y==g[0].size()){
        sum = sos-1;
        return;
    }

    if(vis[x][y]==1) return;
    if(vis[x][y]==2){
        sum = sos-1;
        step = sos - v[x][y];
        inf = true;
        return;
    }

    vis[x][y] = 2;
    v[x][y] = sos;
    if(g[x][y]=='E') dfs(x, y+1, sos+1);
    else if(g[x][y]=='W') dfs(x, y-1, sos+1);
    else if(g[x][y]=='N') dfs(x-1, y, sos+1);
    else dfs(x+1, y, sos+1);
    vis[x][y] = 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n,m,s;

    while(cin >> n >> m >> s && n){
        g.clear();
        inf = false;
        step = 0, sum = 0;
        for(ll i = 0; i < n; i++){
            string temp; cin >> temp;
            g.push_back(temp);
        }

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                vis[i][j] = 0;
            }
        }

        dfs(0, s-1, 1);
        if(inf) cout << (sum-step) << " step(s) before a loop of " << step << " step(s)\n";
        else cout << sum << " step(s) to exit\n";
    }
    return 0;
}