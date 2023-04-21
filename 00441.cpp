#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;
    ll hi = 0;
    while(cin >> n && n){
        ll arr[n];
        if(++hi!=1){
            cout << "\n";
        }
        for(ll i = 0; i < n; i++) cin >> arr[i];

        for(ll i = 0; i+5 < n; i++){
            for(ll j = i+1; j+4 < n; j++){
                for(ll k = j+1; k+3 < n; k++){
                    for(ll l = k+1; l+2 < n; l++){
                        for(ll m = l+1; m+1 < n; m++){
                            for(ll o = m+1; o < n; o++){
                                cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << " " << arr[m] << " " << arr[o] << "\n";
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}