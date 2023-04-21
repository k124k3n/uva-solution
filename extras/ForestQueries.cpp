#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll n,q; cin >> n >> q; ll arr[n][n];

    for(ll i = 0; i < n; i++){
        string s; cin >> s;

        for(ll j = 0; j < n; j++){
            arr[i][j] = (s[j]=='*');
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 1; j < n; j++){
            arr[i][j] += arr[i][j-1]; // horizontal prefix
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 1; j < n; j++){
            arr[j][i] += arr[j-1][i]; // vertical prefix
        }
    }

    // for(ll i = 0; i < n; i++){
    //     for(ll j = 0; j < n; j++){
    //         cout << arr[i][j];
    //     }
    //     cout << "\n";
    // }

    while(q--){
        ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;

        ll up = 0;

        if(x1==1) up = 0;
        else up = arr[x1-2][y2-1];
        if(x1!=1 && y1!=1) up -= arr[x1-2][y1-2];

        ll left = (y1==1)?0:(arr[x2-1][y1-2]);

        cout << arr[x2-1][y2-1]-(up+left) << "\n";
    }

    return 0;
}