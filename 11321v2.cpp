#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second != b.second) return a.second < b.second;
    else if((a.first%2!=0) ^ (b.first%2!=0)){ // a genap, b ganjil
        return(abs(a.first%2) > abs(b.first%2));
    }

    else if(a.first%2!=0 && b.first%2!=0){ // a ganjil b ganjil
        return a.first>b.first;
    }

    else if(a.first%2==0 && b.first%2==0){ // a genap b genap
        return a.first<b.first;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n,m;

    while(cin >> n >> m){
        if(n==0&&m==0) break;
        vector<pair<ll, ll>> arr;

        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            arr.emplace_back(temp, temp%m);
        }

        sort(arr.begin(), arr.end(), comp);
        cout << n << " " << m << "\n";
        for(auto x: arr){
            cout << x.first << "\n";
        }
    }

    cout << "0 0\n";

    return 0;
}