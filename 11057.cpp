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
        ll m;
        unordered_map<ll, bool> hi;
        ll arr[n];

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            hi[arr[i]] = true;
        }

        cin >> m;

        sort(arr, arr+n);

        ll lo = lower_bound(arr, arr+n, m/2) - arr;

        for(ll i = lo; i >= 0; i--){
            if(hi[m-arr[i]]){
                cout << "Peter should buy books whose prices are " << min(arr[i], m-arr[i]) << " and " << max(arr[i], m-arr[i]) << ".\n\n";
                break;
            }
        }
    }
    return 0;
}