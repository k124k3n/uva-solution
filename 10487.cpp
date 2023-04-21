#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;

    ll cs = 0;
    while(cin >> n && n){
        cout << "Case " << ++cs << ":\n";
        ll arr[n];

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr, arr+n);

        ll m; cin >> m;

        while(m--){
            ll temp; cin >> temp;
            ll res = 0;
            ll bs = LLONG_MAX;
            // ll lb = upper_bound(arr, arr+n, temp) - arr;
            // ll pt = min(n-1, lb);

            for(ll i = 0; i < n; i++){
                for(ll j = i+1; j < n; j++){
                    ll ts = abs(arr[i]+arr[j]-temp);
                    // cout << arr[i] << " " << arr[j] << "\n";
                    if(ts < bs){
                        bs = ts;
                        res = arr[i]+arr[j];
                    }
                }
            }

            cout << "Closest sum to " << temp << " is " << res << ".\n";
        }
        
    }
    return 0;
}