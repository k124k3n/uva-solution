#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll n; cin >> n;

    for(ll i = 0; i < n; i++){
        unordered_map<char, ll> f;
        string str; cin >> str;
        for(ll j = 0; str[j]; j++) ++f[str[j]];

        cout << min(f['A']/3, min(f['M'], min(f['R']/2, min(f['T'], min(f['I'], f['G']))))) << "\n";
    }
    return 0;
}