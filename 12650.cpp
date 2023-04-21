#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n,r;

    while(cin >> n >> r){
        unordered_map<ll, bool> found;
        for(ll i = 0; i < r; i++){
            ll temp; cin >> temp;
            found[temp] = true;
        }

        ll hero = 0;

        for(ll i = 1; i <= n; i++){
            if(!found[i]){
                ++hero;
                cout << i << " ";
            }
        }

        if(hero==0) cout << "*\n";
        else cout << "\n";
    }
    return 0;
}