#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    unordered_set<ll> res;

    for(ll i = 1; i <= 50; i++){
        ll p = 1;
        for(ll j = 1; j <= 6; j++){
            p *= i;
        }
        res.insert(p);
    }

    ll n;
    while(cin >> n && n){
        if(res.find(n) != res.end()) cout << "Special\n";
        else cout << "Ordinary\n";
    }
    return 0;
}