#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll s,b;

    while(cin >> s >> b && s && b){
        ll r[s+9], l[s+9];

        for(ll i = 1; i <= s; i++){
            l[i] = i-1;
            r[i] = i+1;
        }

        for(ll i = 0; i < b; i++){
            ll x, y; cin >> x >> y;
            r[l[x]] = r[y];
            l[r[y]] = l[x];

            if(l[x] <= 0) cout << "* ";
            else cout << l[x] << " ";

            if(r[y] >= s+1) cout << "*\n";
            else cout << r[y] << "\n";
        }



        cout << "-\n";

    }

    return 0;
}