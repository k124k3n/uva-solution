#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;

    while(t--){
        ll n,m; cin >> n >> m;
        unordered_map<ll,ll> fA, fB;
        unordered_set<ll> A, B;
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            ++fA[temp];
            A.insert(temp);
        }

        for(ll i = 0; i < m; i++){
            ll temp; cin >> temp;
            ++fB[temp];
            B.insert(temp);
        }

        for(auto x: A){
            if(B.find(x) == B.end()){
                sum += fA[x];
            }
        }

        for(auto x: B){
            if(A.find(x) == A.end()){
                sum += fB[x];
            }
        }

        for(auto x: A){
            if(B.find(x) != B.end()){
                sum += max(fA[x], fB[x]) - min(fA[x], fB[x]);
            }
        }

        cout << sum <<  "\n";


    }
    return 0;
}