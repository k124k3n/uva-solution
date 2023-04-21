#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n,m;


bool comp(ll a, ll b){
    ll remA = abs(a)%2;
    ll remB = abs(b)%2;
    ll modA = (a)%m;
    ll modB = (b)%m;

    if(modA != modB) return (modA < modB);

    if(remA==remB){
        if(remA==1) return a > b;
        else return a < b;
    }

    else{
        return remA > remB;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    while(cin >> n >> m){
        cout << n << " " << m << "\n";
        vector<ll> arr;
        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end(), comp);

        for(ll i = 0; i < arr.size(); i++){
            cout << arr[i];
            cout << "\n";
        }


    }
    return 0;
}