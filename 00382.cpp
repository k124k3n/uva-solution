#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cout << "PERFECTION OUTPUT\n";
    ll n;

    while(cin >> n && n){
        unordered_set<ll> fact;
        if(n!=1)fact.insert(1);
        ll sum = 0;
        for(ll i = 2; i <= sqrt(n); i++){
            if(n%i==0){
                fact.insert(i);
                fact.insert(n/i);
            }
        }

        for(auto x: fact){
            sum += x;
        }

        for(ll i = 1; i <= 5-to_string(n).length(); i++) cout << " ";
        cout << n;
        if(sum==n) cout << "  PERFECT\n";
        else if(sum > n) cout << "  ABUNDANT\n";
        else cout << "  DEFICIENT\n";
            
        
        
    }

    cout << "END OF OUTPUT\n";
    return 0;
}