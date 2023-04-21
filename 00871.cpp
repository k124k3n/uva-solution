#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> g;

ll dfs(ll x, ll y){
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] == '0'){
        return 0;
    }

    ll sum = 1;

    g[x][y] = '0';

    ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    ll dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(ll i = 0; i < 8; i++){
        sum += dfs(x+dx[i], y+dy[i]);
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
    string str; getline(cin, str); // dummy
    ll Max = 0;
    ll cs = 0;
    while(getline(cin, str)){
        if(str == "" || cin.bad()){
            for(ll i = 0; i < g.size(); i++){
                for(ll j = 0; j < g[0].size(); j++){
                    if(g[i][j] == '1'){
                        Max = max(Max, dfs(i, j));
                    }
                }
            }

            cout << Max << "\n\n";
            Max = 0;
            g.clear();
            continue;
        }

        g.push_back(str);
    }

    for(ll i = 0; i < g.size(); i++){
        for(ll j = 0; j < g[0].size(); j++){
            if(g[i][j] == '1'){
                Max = max(Max, dfs(i, j));
            }
        }
    }

    cout << Max << "\n";

    return 0;
}