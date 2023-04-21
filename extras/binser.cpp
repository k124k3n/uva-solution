#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll n, s;

void binser(ll arr[]){
    ll l = 0; ll r = n-1;
    while(l <= r){
        ll mid = (l+r)/2;
        if(arr[mid] == s){
            cout << "Found in " << mid << "\n";
            return;
        }

        else if(arr[mid] > s){
            r = mid-1;
        }

        else l = mid+1;
    }

    cout << "Not found!\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> s;
    ll arr[n];

    for(ll i = 0; i < n; i++) cin >> arr[i];


    binser(arr);

    // for(ll i = 0; i < n; i++) cout << arr[i] << " ";
    // cout << "\n";
    return 0;
}