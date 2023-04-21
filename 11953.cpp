#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> g;

void dfs(ll x, ll y){
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] == '.') return;
    ll dx[4] = {0,1,0,-1};
    ll dy[4] = {1,0,-1,0};

    g[x][y] = '.';

    for(ll i = 0; i < 4; i++){
        dfs(x+dx[i], y+dy[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    ll cs = 0;
    while(t--){
        g.clear();
        cout << "Case " << ++cs << ": ";
        ll sum = 0;
        ll n; cin >> n;
        for(ll i = 0; i < n; i++){
            string str; cin >> str;
            g.push_back(str);
        }

        for(ll i = 0; i < g.size(); i++){
            for(ll j = 0; j < g[0].size(); j++){
                if(g[i][j] == 'x'){
                    dfs(i, j);
                    ++sum;
                }
            }
        }

        cout << sum << "\n";
    }
    return 0;
}