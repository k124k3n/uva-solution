#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll temp = 0;
bool visited[101][101];
vector<ll> resx, resy;

void dfs(vector<string> g, ll n, ll m){
    // cout << n << " " << m << "\n";
    if(n < 0 || n >= g.size() || m < 0 || m >= g[0].size() || visited[n][m] || g[n][m] == 'L'){
        // cout << "END PLZ\n";
        return;
    }
    ++temp;
    // cout << "temp = " << temp << "\n";
    visited[n][m] = true;
    ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    ll dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(ll i = 0; i < 8; i++){
        dfs(g, n+dx[i], m+dy[i]);
    }

    // visited[n][m] = false;
}

void rst(vector<string> g, ll n, ll m){
    // cout << n << " " << m << "\n";
    if(n < 0 || n >= g.size() || m < 0 || m >= g[0].size() || !visited[n][m] || g[n][m] == 'L'){
        // cout << "END PLZ\n";
        return;
    }

    // cout << "temp = " << temp << "\n";
    visited[n][m] = false;
    ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    ll dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(ll i = 0; i < 8; i++){
        rst(g, n+dx[i], m+dy[i]);
    }

    // visited[n][m] = false;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    cin.ignore();
    string str; getline(cin, str);
    while(t--){
        ll x,y;

        
        vector<string> g;

        while(getline(cin, str)){
            if(isdigit(str[0])){
                stringstream ss(str);
                vector<ll> te;
                while(ss >> temp){
                    te.push_back(temp);
                }

                temp = 0;
                // cout << g.size() << "\n";
                dfs(g, te[0]-1, te[1]-1);
                rst(g, te[0]-1, te[1]-1);
                // for(ll j = 0; j < resx.size(); j++){
                //     visited[resx[j]][resy[j]] = false;
                // }

                // resx.clear(); resy.clear();
                // cout << te[0] << " " << te[1] << "\n";
                cout << temp << "\n";
                break;
            }

            // cout << str << "\n";
            g.push_back(str);
            
        }

        while(getline(cin, str)){
            if(str == "") break;
            // cout << str << "\n";
            stringstream ss(str); ll ge; vector<ll> te;
            while(ss >> ge){
                te.push_back(ge);
            }

            temp = 0;

            dfs(g, te[0]-1, te[1]-1);
            rst(g, te[0]-1, te[1]-1);
            // for(ll j = 0; j < resx.size(); j++){
            //         visited[resx[j]][resy[j]] = false;
            // }

            // resx.clear(); resy.clear();
            // cout << te[0] << " " << te[1] << "\n";
            cout << temp << "\n";
        }

        if(t != 0) cout << "\n";
    }
    return 0;
}