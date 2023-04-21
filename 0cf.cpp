#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t; cin >> t;
    ll mod = 1e9+7;
    while(t--){
        ll n; cin >> n;
        bool found = false;
        bool rl = false;
        vector<ll> arr[n+1];
        set<ll> hi;
        for(ll i = 0; i < n; i++){
            ll k; cin >> k;
            found = true;
            for(ll j = 0; j < k; j++){
                ll temp; cin >> temp;
                arr[i].push_back(temp);
            }

        }


        for(ll i = 0; i < n; i++){
            found = true;
            for(auto x: arr[i]){
                if(i!=0 && hi.find(x) == hi.end()) found = false;
            }

            for(auto x: arr[i]){
                hi.insert(x);
            }

            if(found && i!=0) rl = true;
        }

        hi.clear();

        for(ll i = n-1; i >= 0; i--){
            found = true;
            for(auto x: arr[i]){
                if(i!=(n-1) && hi.find(x) == hi.end()) found = false;
            }

            for(auto x: arr[i]){
                hi.insert(x);
            }

            if(found && i!=(n-1)) rl = true;
        }

        if(rl) cout << "Yes\n";
        else cout << "No\n";

    }
}