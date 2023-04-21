#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    while(cin >> n && n){
        ll pos[n] = {0};
        bool found = true;
        for(ll i = 0; i < n; i++){
            ll a, b; cin >> a >> b;
            if((i+b) >= n || (i+b) < 0 || pos[i+b] != 0){
                found = false;
                continue;
            }

            pos[i+b] = a;
        }

        if(!found){
            cout << -1 << "\n";
            continue;
        }

        for(ll i = 0; i < n; i++){
            cout << pos[i];
            if(i != n-1) cout << " ";
        } cout << "\n";
    }
    return 0;
}