#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> g;
vector<string> d;
ll touch[102][102];
ll sum = 0;

bool tc(ll x, ll y){
    if(x < 0 || y < 0 || x >= d.size() || y >= d[0].size()) return true;
    if(d[x][y] == 'V') return false;
    d[x][y] = 'V';


    ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    ll dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(ll i = 0; i < 8; i++){
        if(tc(x+dx[i], y+dy[i])){
            return true;
        }
    }

    return false;



    

}

ll dfs(ll x, ll y){
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] == 'V') return 0;
    char riil = g[x][y];

    ++sum;
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t; cin >> t;

    while(t--){
        sum = 0;
        g.clear();
        d.clear();
        bool found = false;
        bool lurus = true;
        bool correct = true;
        ll r,c,d; cin >> r >> c >> d;
        for(ll i = 0; i < r; i++){
            for(ll j = 0; j < c; j++){
                touch[i][j] = -1;
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
            d.push_back(str);
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
            if(dfs(i, j) != c){
                correct = false;
                break;
            }
        }

        // cout << sum << " " << correct << " " << lurus << "\n";
        if(sum == r*c && correct && lurus) cout << "solved\n";
        else cout << "not solved\n";
    }
    return 0;
}