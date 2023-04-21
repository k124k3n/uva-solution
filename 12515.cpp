#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll m,q; cin >> m >> q;

    string mov[m];

    for(ll i = 0; i < m; i++){
        cin >> mov[i];
    }

    while(q--){
        string s; cin >> s;

        ll ms = 0;
        ll ind = 0;
        for(ll i = 0; i < m; i++){
            if(mov[i].length() < s.length()) continue;
            for(ll j = 0; j <= mov[i].length() - s.length(); j++){
                ll x = 0;
                for(ll k = j; k < j+s.length(); k++){
                    x += (s[k-j] == mov[i][k]);
                }
                if(x > ms){
                    ms = x;
                    ind = i+1;
                }
            }
        }

        cout << ind << "\n";
    }

    return 0;
}