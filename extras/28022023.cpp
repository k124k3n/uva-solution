#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> ganj;
    ll sum = 0;
    for(ll i =1; i<= n; i++){

        if(i%2){
            ganj.push_back(i);
            sum += i;
        }
    }

    cout << ganj.size() << "\n";

    for(auto x: ganj){
        cout << x << ' ';
    } cout << "\n";

    cout << sum << "\n";
    
    return 0;
}