#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    while(cin >> n && n){
        ll p = -1;
        string arr[n+1], a, b;
        cin >> a >> b;

        p = (b.length()-1)%n;
        arr[p] = a;

        for(ll i = 1; i < n; i++){
            cin >> a >> b;
            ll sum = 0;

            while(sum < b.length()){
                p = (p+1)%n;
                if(!arr[p][0]) ++sum;
            }

            arr[p] = a;
            
        }

        for(ll i = 0; i < n; i++){
            cout << arr[i];
            if(i!=n-1) cout << " ";
        } cout << "\n";
    }
    return 0;
}