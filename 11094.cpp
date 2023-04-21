#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> g;

char hi;

ll dfs(ll x, ll y){
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] != hi) return 0;
    
    ll sum = (g[x][y] == hi);
    g[x][y] = '`';
    ll dx[4] = {1, 0, -1, 0};
    ll dy[4] = {0, 1, 0, -1};

    for(ll i = 0; i < 4; i++){
        sum += dfs(x+dx[i], (y+dy[i]+g[0].size())%g[0].size());
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n,m;

    while(cin >> n >> m){
        g.clear();
        for(ll i = 0; i < n; i++){
            string str; cin >> str;
            g.push_back(str);
        }

        ll i,j; cin >> i >> j;
        hi = g[i][j];
        ll hm = dfs(i, j);
        ll Max = 0;
        
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                if(g[i][j] == hi){
                    Max = max(Max, dfs(i, j));
                }
            }
        }

        cout << Max << "\n";
    }
    return 0;
}