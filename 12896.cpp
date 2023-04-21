#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<ll, vector<char>> p({
    {1, {'.', ',', '?', '"'}}, {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}},
    {5, {'j', 'k', 'l'}}, {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}}, 
    {9, {'w', 'x', 'y', 'z'}}, {0, {' '}},
});


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;

    while(t--){
        ll n; cin >> n; ll arr[n];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            cout << p[arr[i]][temp-1];
        } cout << "\n";

    }

    return 0;
}