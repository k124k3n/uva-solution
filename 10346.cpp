#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n,k;

    while(cin >> n >> k){
        ll sum = 0;

        while(n >= k){
            sum += n-(n%k);
            n = (n%k)+(n/k);
        }

        cout << sum+n << "\n";
    }
    return 0;
}