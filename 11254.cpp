#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> deret;

void gen(){
    deret.push_back(0);

    for(ll i = 1; true; i++){
        if(i + deret[i-1] > 1'500'000'000) break;
        deret.push_back(i+deret[i-1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    gen();

    ll n;

    while(cin >> n && n > 0){
        cout << n << " = ";

        ll up = lower_bound(deret.begin(), deret.end(), n) - deret.begin();
        ll bil = deret[up] - n;
        ll lo = lower_bound(deret.begin(), deret.end(), bil) - deret.begin();
        if(deret[lo] == bil){
            cout << lo+1 << " + ... + " << up << "\n";
        }

        else cout << n << " + ... + " << n << "\n";
    }

    return 0;
}