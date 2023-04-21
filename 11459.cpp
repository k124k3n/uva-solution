#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<ll,ll> ls;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;

    while(t--){
        ls.clear();
        bool complete = false;
        ll a,b,c; cin >> a >> b >> c;
        ll player[a];
        for(ll i = 0; i < a; i++) player[i] = 1;

        for(ll i = 0; i < b; i++){
            ll st, en; cin >> st >> en;
            ls[st] = en;
        }

        for(ll i = 0; i < c; i++){
            ll temp; cin >> temp;
            if(!complete && a){
                player[i%a] = min((ll) 100, player[i%a]+temp);
                if(ls[player[i%a]]) player[i%a] = ls[player[i%a]];
                if(player[i%a] == 100) complete = true;
            }
        }

        for(ll i = 0; i < a; i++){
            cout << "Position of player " << i+1 << " is " << player[i] << ".\n";
        }
    }

    return 0;
}