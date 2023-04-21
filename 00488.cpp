#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        ll a, b; cin >> a >> b;

        for(ll i = 0; i < b; i++){
            for(ll j = 1; j <= a; j++){ // first mountain
                for(ll k = 1; k <= j; k++){
                    cout << j;
                }
                cout << "\n";
            }

            for(ll j = a-1; j >= 1; j--){ // second mountain
                for(ll k = 1; k <= j; k++){
                    cout << j;
                }
                cout << "\n";
            }

            if(i != b-1) cout << "\n";
        }


        if(t!=0) cout << "\n";

        
    }
    return 0;
}