#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;

    while(cin >> n){
        ll A[n], B[n];
        ll x = 0;
        unordered_map<ll, ll> ind;

        for(ll i = 0; i < n; i++){
            cin >> A[i];
            ind[A[i]] = i;
        }

        for(ll i = 0; i < n; i++){
            cin >> B[i];
        }

        for(ll i = 0; i < n; i++){
            for(ll j = n-1; j >= 0; j--){
                if(A[i]!=B[j]) continue;

                for(ll k = j; k > i; k--){
                    swap(B[k], B[k-1]);
                    ++x;
                }
                
            }
        }
        
        cout << x << "\n";
    }
    return 0;
}