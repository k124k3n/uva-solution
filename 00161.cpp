#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    vector<ll> res;

    while(cin >> n){
        if(n==0 && res.size()==0){
            ll d1, d2; cin >> d1 >> d2;
            continue;
        }

        if(n==0){
            ll Min = LLONG_MAX;
            for(auto x: res){
                Min = min(Min, x);
            }

            ll st = Min*2;

            bool found = false;

            for(ll i = st; i <= 18000; i++){
                ll sum = 0;
                for(auto x: res){
                    bool g = (i%(x*2) < x-5);
                    sum += g;
                }

                if(sum == res.size()){
                    ll temp = i;
                    ll h = temp/3600;
                    temp %= 3600;
                    ll m = temp/60;
                    temp %= 60;
                    ll s = temp;
                    printf("%02lld:%02lld:%02lld\n", h,m,s);
                    found = true;
                    break;
                }
            }

            if(!found) cout << "Signals fail to synchronise in 5 hours\n";
            res.clear();
            continue;
        }

        res.push_back(n);
    }
    return 0;
}