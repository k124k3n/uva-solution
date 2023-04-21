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

        ll Max = LLONG_MIN;

        ll k = pow(2,n); ll p[k], sum[k];
        for(ll i = 0; i < k; i++){
            cin >> p[i];
            sum[i] = 0;
        }

        for(ll i = 0; i < k; i++){
            for(ll j = 0; j < n; j++){
                ll now = p[(i^(1<<j))];
                sum[i] += now;
            }

            // cout << "sum[" << i << "] = " << sum[i] << "\n";
        }

        for(ll i = 0; i < k; i++){
            for(ll j = 0; j < n; j++){
                ll now = (i^(1<<j));
                Max = max(Max, sum[i]+sum[now]);
            }
        }

        cout << Max << "\n";
    }
    return 0;
}