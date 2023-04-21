#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    ll cs = 0;
    while(t--){
        cout << "Case " << ++cs << ": ";
        ll n; cin >> n;
        ll arr[n+1];
        arr[0] = 0;
        for(ll i = 1; i <= n; i++) cin >> arr[i];
        ll l = 1, r = pow(2, 32);

        while(l <= r){
            ll mid = (l+r)/2;
            // do the function
            ll temp = mid;
            bool failed = false;
            for(ll i = 1; i <= n; i++){
                if(arr[i] - arr[i-1] > temp){
                    failed = true;
                    break;
                }
                else if(arr[i] - arr[i-1] == temp){
                    --temp;
                }
            }

            if(failed) l = mid+1;
            else r = mid-1;
        }

        cout << l << "\n";
    }

    return 0;
}