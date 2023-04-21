#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> g;

ll dfs(ll x, ll y, char wh){
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] != wh) return 0;
    ll sum = 1;
    g[x][y] = 'Y';

    ll dx[4] = {1,0,-1,0};
    ll dy[4] = {0,1,0,-1};

    for(ll i = 0; i < 4; i++){
        sum += dfs(x+dx[i], y+dy[i], wh);
    }

    return sum;
}

ll dfst(ll x, ll y, unordered_set<char> &h){
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] == 'Y') return 0;
    if(g[x][y] == 'O' || g[x][y] == 'X'){
        h.insert(g[x][y]);
        return 0;
    }

    ll sum = 1;

    g[x][y] = 'Y';

    ll dx[4] = {1,0,-1,0};
    ll dy[4] = {0,1,0,-1};

    for(ll i = 0; i < 4; i++){
        sum += dfst(x+dx[i], y+dy[i], h);
    }

    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    cin.ignore();
    while(t--){
        g.clear();
        unordered_map<char, ll> sum;
        for(ll i = 0; i < 9; i++){
            string str; cin >> str;
            g.push_back(str);
        }

        for(ll i = 0; i < 9; i++){
            for(ll j = 0; j < 9; j++){
                unordered_set<char> hi;
                if(g[i][j] == 'Y') continue;
        
                if(g[i][j] == '.'){
                    ll res = dfst(i, j, hi);
                    // cout << hi.size() << "\n";
                    if(hi.size() == 1){
                        sum[*(hi.begin())] += res;
                    }

                }
            }
        }

        for(ll i = 0; i < 9; i++){
            for(ll j = 0; j < 9; j++){
                if(g[i][j] == 'Y') continue;
                if(g[i][j] != '.'){
                    char temp = g[i][j];

                    ll res = dfs(i, j, g[i][j]);
                    sum[temp] += res;
                    // cout << temp << " += " << res << "\n";
                }
            }
        }

        
        cout << "Black " << sum['X'] << " White " << sum['O'] << "\n";
    }

    return 0;
}