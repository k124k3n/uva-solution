#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> gen; ll sum = 0;

    cout << n/12 << "\n";

    for(ll i = 12; i <= n; i += 12){
        cout << i << " ";
        sum += i;
    } cout << "\n";

    cout << sum << "\n";
    
    return 0;
}