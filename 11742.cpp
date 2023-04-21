#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dt{
    ll a,b,c;
    dt(ll _a, ll _b, ll _c){
        a = _a;
        b = _b;
        c = _c;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll fact[9];
    fact[1] = 1;

    for(ll i = 2; i <= 8; i++) fact[i] = i * fact[i-1];

    ll n,m;

    while(cin >> n >> m && n){
        vector<dt> com;
        ll sum = 0;
        if(m==0){
            cout << fact[n] << "\n";
            continue;
        }

        vector<ll> arr;

        for(ll i = 1; i <= n; i++){
            arr.push_back(i);
        }

        for(ll i = 0; i < m; i++){
            ll a, b, c; cin >> a >> b >> c;
            com.emplace_back(a, b, c);
        }
        
        do{
            unordered_map<ll, ll> pos;

            bool ada = true;

            for(ll i = 0; i < n; i++){
                pos[arr[i]] = i;
            }

            for(auto &[a, b, c]: com){
                ada &= (pos[a] - pos[b] <= c);
            }

            sum += ada;
        } while(next_permutation(arr.begin(), arr.end()));

        cout << sum << "\n";
    }
    return 0;
}