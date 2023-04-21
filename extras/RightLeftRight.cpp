#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ll n; cin >> n;

    ll sum = 0;
    for(ll i = 0; i < n; i++){
        ll a, b, c; cin >> a >> b >> c;
        bool b1 = a%2==0 && a != 0;
        bool b2 = b%2!=0;
        bool b3 = c%2==0 && c != 0;
        if(b1&&b2&&b3) ++ sum;
    }

    cout << abs(sum - (n-sum)) << "\n";

    return 0;
}