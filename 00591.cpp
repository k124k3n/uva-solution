#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n;

    ll cs = 0;
    while(cin >> n && n){
        cout << "Set #" << ++cs << "\n";
        vector<ll> arr;
        ll rate = 0;
        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            arr.push_back(temp);
            rate += temp;
        }

        rate /= n;

        ll tot = 0;
        for(ll i = 0; i < n; i++){
            if(arr[i] > rate) tot += arr[i] - rate;
        }

        cout << "The minimum number of moves is " << tot << ".\n\n";
    }
    return 0;
}