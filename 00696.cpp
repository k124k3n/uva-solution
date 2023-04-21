#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;

    while(cin >> n >> m && n && m){
        if(min(n,m) == 1) cout << max(n,m);
        else if(min(n,m) == 2){           
            if(max(n,m) % 4 == 0) cout << max(n,m);
            else if(max(n,m) % 4 == 1) cout << max(n,m) + 1;
            else cout << max(n,m) - (max(n,m) % 2) + 2;
        }
        else cout << ceil((double) n*m/2);
        cout << " knights may be placed on a " << n << " row " << m << " column board.\n";
    }
    return 0;
}