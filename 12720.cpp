#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    ll cs = 0;
    ll dp[100000+3];
    dp[0] = 1;

    for(ll i = 1; i <= 100000; i++){
        dp[i] = ((dp[i-1]%mod)*2)%mod;
    }

    // cout << dp[64] << " " << dp[65] << "\n";
    while(t--){
        cout << "Case #" << ++cs << ": ";
        string a; cin >> a;
        string res;
        ll fin = 0;
        if(a.length()==1){
            cout << (stoi(a)&1) <<"\n";
            continue;
        }

        ll j = a.length();

        if(a.length()%2){
            if(stoi(string(1, a[a.length()/2]))) fin = ((fin%mod)+dp[j-1])%mod;
            --j;
        }
        
        ll p = (a.length()%2) ? (p=2) : (p=1);
        for(ll i = a.length()/2-1; i >= 0; i--, p += 2, j -= 2){
            // string temp = string(1, ) + string(1, min(a[i], a[i+p]));
            ll resA = ((max(a[i], a[i+p]) - '0')*(ll)pow(2, j-1))%mod;
            ll resB = ((min(a[i], a[i+p]) - '0')*(ll)pow(2, j-2))%mod;

            if((max(a[i], a[i+p]) - '0')){
                fin = ((fin%mod)+dp[j-1])%mod;
            }

            if((min(a[i], a[i+p]) - '0')){
                fin = ((fin%mod)+dp[j-2])%mod;
            }

            // cout << (max(a[i], a[i+p]) - '0')*pow(2, j-1) << " " << (min(a[i], a[i+p]) - '0')*pow(2, j-2) << "\n";
        }

        cout << fin << "\n";

    }
    return 0;
}