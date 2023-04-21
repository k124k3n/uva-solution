#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll p[102][102];
string board[102];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m, cse = 1;
    while(cin >> n >> m && n){
        if(cse != 1 && n != 0) cout << "\n";
        for(ll i = 0; i < n; i++){
            cin >> board[i];
            for(ll j = 0; j < m; j++){
                p[i][j] = 0;
            }
        }

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                if(board[i][j]=='*'){
                    ll x[8] = {-1,-1,-1,0,1,1,1,0};
                    ll y[8] = {-1,0,1,1,1,0,-1,-1};
                    for(ll k = 0; k < 8; k++){
                        ll imove = i + x[k]; ll jmove = j + y[k];
                        bool a = imove >= 0 && imove < n;
                        bool b = jmove >= 0 && jmove < m;
                        if(a && b) ++p[imove][jmove];
                    }
                }
            }
        }

        cout << "Field #" << cse << ":\n";

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                if(board[i][j] == '*') cout << '*';
                else cout << p[i][j];
            }
            cout << "\n";
        }

        ++cse;
    }

    return 0;
}