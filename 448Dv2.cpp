#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n,m,k; cin >> n >> m >> k;
    k = n*m-k+1;
    ll l = 1;
    ll r = n*m;

    ll ans;

    while(l < r){
        ll mid = l + (r-l)/2;
        ll sum = 0;
        ll same = 0;
        for(ll i = 1; i <= n; i++){
            // cout << i << "\n";
            if(mid%i==0 && mid/i <= m){ // udh pasti ada dia disitu
                ++same;
                sum += mid/i-1;
                // cout << "sum += " << mid/i-1 << "\n";
            }

            else{
                sum += min(m, mid/i);
                // cout << "sum += " << min(n, mid/i) << "\n";
            }
        }

        cout << l << " " << r << "  " << mid << "  " << sum << " " << same << "\n";

        // sum = jmlh elemen yg < mid
        // same = jmlh elemen yg == mid
        // first conditional: sum+1 <= k <= sum+same
        if(same != 0 && sum+1 <= k && sum+same >= k){ // FOUND!
            cout << mid << "\n";
            return 0;
        }

        else if(sum+same < k){
            l = mid+1;
        }

        else r = mid-1;
    }

    cout << l << "\n";

    return 0;
}