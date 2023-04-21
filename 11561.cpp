#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> g;

ll dfs(ll x, ll y){
    // cout << x << " " << y << "\n";
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] == '#' || g[x][y] == 'T') return 0;

    ll sum = 0;
    if(g[x][y] == 'G') ++sum;

    ll dx[4] = {-1, 0, 1, 0};
    ll dy[4] = {0, 1, 0, -1};

    g[x][y] = '#';

    // for(ll i = 0; i < g.size(); i++){
    //     cout << g[i] << "\n";
    // } cout << "\n";

    for(ll i = 0; i < 4; i++){
        ll xx = x+dx[i]; ll yy = y+dy[i];

        if(xx < 0 || yy < 0 || xx >= g.size() || yy >= g[0].size() || g[xx][yy] == '#'){
            continue;
        }

        if(g[xx][yy] == 'T') return sum;
    }

    for(ll i = 0; i < 4; i++){
        sum += dfs(x+dx[i], y+dy[i]);
    }

    // cout << x << " " << y << "\n";
    // cout << "sum = " << sum << "\n";
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll x, y;

    while(cin >> y >> x){
        g.clear();
        cin.ignore();
        bool found = false;
        for(ll i = 0; i < x; i++){
            string str; getline(cin, str);
            // cout << str << "\n";
            g.push_back(str);
        }

        for(ll i = 0; i < x && !found; i++){
            for(ll j = 0; j < y && !found; j++){
                if(g[i][j] == 'P'){
                    found = true;
                    // cout << i << " " << j << "\n";
                    cout << dfs(i, j) << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}