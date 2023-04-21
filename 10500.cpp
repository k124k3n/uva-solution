#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, st, en, mv;
char maps[100][100], res[100][100];
bool vis[100][100];

void ex(ll a, ll b){
    ll x[4] = {-1, 0, 1, 0};
    ll y[4] = {0, 1, 0, -1};
    bool found = false;
    ll xm, ym;
    ll xt=-1, yt=-1;

    for(ll i = 0; i < 4; i++){
        xm = a+x[i];
        ym = b+y[i];
        if(xm >= 0 && xm < n && ym >= 0 && ym < m){
            res[xm][ym] = maps[xm][ym];
            if(!found && !vis[xm][ym] && res[xm][ym] != 'X'){
                found = true;
                vis[xm][ym] = true;
                xt=xm, yt=ym;
                ++mv;
            }

            
        }
    }

    // for(ll i = 0; i < n; i++){
    //         for(ll j = 0; j < m; j++) cout << res[i][j] << " ";
    //         cout << "\n";
    // } cout << "\n";


    if(xt!=-1&&yt!=-1){
        ex(xt, yt);
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    while(cin >> n >> m && n && m){
        cout << "\n";
        mv = 0;
        cin >> st >> en;
        
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                cin >> maps[i][j];
                res[i][j] = '?';
                vis[i][j] = false;
            }
        }

        vis[st-1][en-1] = true;

        res[st-1][en-1] = maps[st-1][en-1];
        ex(st-1, en-1);

        for(ll i = 0; i < n; i++){

            for(ll j = 0; j < m; j++) cout << "|---";
            cout << "|\n";

            for(ll j = 0; j < m; j++){
                cout << "| " << res[i][j] << " ";
            }
            cout << "|\n";
            
        }

        for(ll j = 0; j < m; j++) cout << "|---";
        cout << "|\n";


        cout << "\n";
        cout << "NUMBER OF MOVEMENTS: " << mv << "\n";


    }

    return 0;
}