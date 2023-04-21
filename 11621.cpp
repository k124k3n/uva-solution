#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<ll> num;
    ll two = 1;

    for(ll i = 0; i <= 32; i++){
        ll thr = 1;
        

        while((ll)two*thr <= 4300000000){
            ll ans = two*thr;
            num.push_back(ans);
            thr *= 3;
        }

        two *= 2;
    }

    sort(num.begin(), num.end());

    ll n;

    while(cin >> n && n){
        ll ind = lower_bound(num.begin(), num.end(), n) - num.begin();

        cout << num[ind] << "\n";
    }
    return 0;
}