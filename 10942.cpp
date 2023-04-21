#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k; vector<ll> arr;

        set<ll> res;
        for(ll i = 0; i < m; i++){
            ll temp; cin >> temp;
            res.insert(temp);
        }

        arr.push_back(0);

        for(auto x: res){
            arr.push_back(x);
        }
        ll Min = LLONG_MAX;

        if(k==1){
            cout << "YES\n";
            continue;
        }

        for(ll i = 1; i < arr.size(); i++){
            Min = min(Min, arr[i]-arr[i-1]);
        }

        for(ll i = 1; i < arr.size(); i++){
            arr[i] -= arr[i-1];
        }


        if(Min<=k&&arr[n-1]<=k) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
