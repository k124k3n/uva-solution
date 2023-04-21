#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> g;

void dfs(ll x, ll y){
    if(x < 0 || y < 0 || x >= g.size() || y >= g.size() || g[x][y] == '0'){
        return;
    }

    g[x][y] = '0';

    ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    ll dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(ll i = 0; i < 8; i++){
        dfs(x+dx[i], y+dy[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    ll cs = 0;
    while(cin >> n){
        ll sum = 0;
        g.clear();
        cin.ignore();
        for(ll i = 0; i < n; i++){
            string str; getline(cin, str);
            g.push_back(str);
        }

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                if(g[i][j] == '1'){
                    dfs(i, j);
                    ++sum;
                }
            }
        }

        cout << "Image number " << ++cs << " contains " << sum << " war eagles.\n";
    }
    return 0;
}