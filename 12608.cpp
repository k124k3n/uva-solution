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
        ll w,n; cin >> w >> n;
        pair<ll, ll> arr[n+5];
        arr[0] = {0,0};

        ll now = 0, sum = 0;

        // cout << w << " " << n << "\n";
        for(ll i = 1; i <= n; i++){
            cin >> arr[i].first >> arr[i].second;
        }

        for(ll i = 1; i <= n; i++){
            ll d = arr[i].first, ww = arr[i].second;

            if(now==0) sum += arr[i].first;
            else sum += arr[i].first - arr[i-1].first;
            // cout << i-1 << " to " << i << " = " << arr[i].first - arr[i-1].first << "\n";

            if((now+ww)>w){ // x + Wi > Capacity, kosongin
                sum += 2*d;
                // cout << "go home from "  << i << ": " << 2*d << "\n";
                now = 0;
            }

            now += ww;

            if(now==w && i != n){ // x == Capacity, kosongin
                sum += d;
                // cout << "go home from "  << i << ": " << d << "\n";
                now = 0;                
            }
        }
        sum += arr[n].first;
        cout << sum << "\n";
    }
    return 0;
}