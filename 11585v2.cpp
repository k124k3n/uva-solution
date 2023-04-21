#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> g;
vector<string> gg;

ll ada[102][102];
ll touch[102][102]; // touch edge

ll sum = 0;

bool tc(ll x, ll y){
    if((x == 0 || y == 0 || x == gg.size() -1 || y == gg[0].size() - 1) && gg[x][y] == '.'){
        return true;
    }

    if(gg[x][y] != '.') return false;

    if(touch[x][y] != -1) return touch[x][y];
    if(gg[x][y] != '.') return false;

    gg[x][y] = 'V';


    ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    ll dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(ll i = 0; i < 8; i++){
        if(tc(x+dx[i], y+dy[i])){
            touch[x][y] = true;
            // cout << x << " " << y << " = true\n";
            return true;
        }
    }

    // cout << x << " " << y << " = false\n";
    touch[x][y] = false;
    return false;
}

ll dfs(ll x, ll y){
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] == 'V') return 0;
    char riil = g[x][y];

    g[x][y]  = 'V';
    if(riil == '#' || riil == 'B') return 0;

    ll t = 1;

    ll dx[4] = {1, 0, -1, 0};
    ll dy[4] = {0, 1, 0, -1};

    for(ll i = 0; i < 4; i++){
        t += dfs(x+dx[i], y+dy[i]);
    }
    return t;
}

// kurang handle 8 flood-fill for sum

void dfsb(ll x, ll y){
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] == 'B' || g[x][y] == '.') return;
    char riil = g[x][y];

    g[x][y]  = 'B';

    // for(ll i = 0; i < g.size(); i++){
    //     cout << g[i] << "\n";
    // } cout << "\n";

    ll dx[4] = {1, 0, -1, 0};
    ll dy[4] = {0, 1, 0, -1};

    for(ll i = 0; i < 4; i++){
        dfsb(x+dx[i], y+dy[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t; cin >> t;

    while(t--){
        sum = 0;
        g.clear(); gg.clear();
        bool found = false;
        bool lurus = true;
        bool correct = true;
        bool rigged = false;
        ll r,c,d; cin >> r >> c >> d;
        for(ll i = 0; i < r; i++){
            for(ll j = 0; j < c; j++){
                touch[i][j] = -1;
                ada[i][j] = 0;
            }
        }

        vector<tuple<ll,ll,ll>> hi;
        while(d--){
            ll x,y,z; cin >> x >> y >> z;
            hi.emplace_back(x,y,z);
        }
        
        for(ll i = 0; i < r; i++){
            string str; cin >> str;
            g.push_back(str);
            gg.push_back(str);
        }

        // check_sum
        for(ll i = 0; i < r; i++){
            for(ll j = 0; j < c; j++){
                if(g[i][j] == '.' && !ada[i][j]){
                    ++sum;
                    ada[i][j] = true;
                    ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
                    ll dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
                    for(ll k = 0; k < 8; k++){
                        ll xx = i+dx[k];
                        ll yy = j+dy[k];
                        if(xx < 0 || yy < 0 || xx >= g.size() || yy >= g[0].size() || ada[xx][yy] || g[xx][yy] == '.') continue;
                        ada[xx][yy] = true;
                        ++sum;
                    }
                }
            }
        }

        for(ll i = 0; i < r && !found; i++){
            for(ll j = 0; j < c && !found; j++){
                if(g[i][j] == '#'){
                    dfsb(i, j);
                    found = true;
                    break;
                }
            }
        }

        for(ll i = 0; i < r && lurus; i++){
            for(ll j = 0; j < c && lurus; j++){
                if(g[i][j]=='#'){
                    lurus = false;
                    break;
                }
            }
        }

        for(auto &[i, j, c]: hi){
            if(dfs(i, j) != c || !tc(i,j)){
                // cout << i << " " << j << " = " << tc(i,j) << "\n";
                correct = false;
                break;
            }
        }

        for(ll i = 0; i < r && !rigged; i++){
            for(ll j = 0; j < c && !rigged; j++){
                if(g[i][j] == '.'){
                    rigged = true;
                }
            }
        }

        // cout << sum << " " << correct << " " << lurus << "\n";
        if((sum == r*c || r < 2 || c < 2) && correct && lurus && !rigged) cout << "solved\n";
        else cout << "not solved\n";
    }
    return 0;
}