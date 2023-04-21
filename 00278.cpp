#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        char x; ll a,b; cin >> x >> a >> b;
        if(x == 'r') cout << min(a,b) << "\n";

        else if(x == 'k') cout << ceil((double)a*b/2) << "\n";
        else if(x == 'K') cout << ceil((double)a/2) * ceil((double)b/2) << "\n";
        else{
            if(a==2&&b==2) cout << 1 << "\n";
            else if(a==3&&b==3) cout << 2 << "\n";
            else cout << min(a,b) << "\n";
        }
    }

    
    return 0;
}