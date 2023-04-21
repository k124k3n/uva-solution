#include <bits/stdc++.h>
using namespace std;

#define ll long long

class FenwickTree{
    private:
        vector<ll> f;

        ll LSOne(ll i){return (i&(-i));}

    public:
        FenwickTree(ll n){
            f.assign(n+1,0);
        }

        void update(ll x, ll val){
            for(ll i = x; i <= f.size()-1; i += LSOne(i)){
                f[i] += val;
                // cout << "f[" << i << "] = " << f[i] << "\n";
            }
        }

        void update(ll a, ll b, ll u){
            update(a, u);
            update(b+1, 0-u);
        }

        ll print(ll x){
            ll sum = 0;
            for(ll i = x; i >= 1; i -= LSOne(i)){
                sum += f[i];

                // cout << "f[" << i << "] = " << f[i] << "\n";
            }


            return sum;
        }


};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll n,q; cin >> n >> q; 
    vector<ll> arr; arr.assign(n+1, 0);

    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
    }

    FenwickTree ft(n);

    for(ll i = 0; i < q; i++){
        ll com; cin >> com;

        if(com==1){
            ll a,b,u; cin >> a >> b >> u;
            ft.update(a,b,u);
        }

        else{
            ll k; cin >> k;
            cout << ft.print(k)+arr[k] << "\n";
            
        }
    }

    return 0;
}