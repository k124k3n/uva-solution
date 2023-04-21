#include <bits/stdc++.h>
using namespace std;

#define ll long long

class FenwickTree{
    private:
        vector<ll> f;
    
    public:
        ll LSOne(ll i){return (i&(-i));}
        FenwickTree(ll n, vector<ll> &arr){
            f.assign(n+1, 0);
            for(ll i = 1; i <= n; i++){
                f[i] += arr[i];
                if(i+LSOne(i) <= n){
                    f[i+LSOne(i)] += f[i];
                }
            }
        }

        void update(ll x, ll v){
            for(ll i = x; i <= f.size()-1; i += LSOne(i)){
                f[i] += v;
            }
        }

        ll print(ll k){
            ll sum = 0;
            for(ll i = k; i >= 1; i -= LSOne(i)){
                sum += f[i];
            }

            return sum;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ll n,q; cin >> n >> q; 
    vector<ll> arr; arr.assign(n+1, 0);

    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
    }

    FenwickTree ft(n, arr);

    for(ll i = 0; i < q; i++){
        ll com; cin >> com;

        if(com==1){
            ll a,b,u; cin >> a >> b >> u;
            ft.update(a,u);
            ft.update(b+1,-u);
        }

        else{
            ll k; cin >> k;
            cout << ft.print(k) << "\n";
            cout << ft.print(k-1) << "\n";
        }
    }

    return 0;
}