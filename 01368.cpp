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
        ll m, n; cin >> m >> n;
        char res[n]; ll Max[n] = {0};
        ll sum = 0;
        unordered_map<char,ll> f[n];
        for(ll p = 0; p < m; p++){
            
            string str; cin >> str;
            for(ll i = 0; i < n; i++){
                ++f[i][str[i]];
                
                if(f[i][str[i]] > Max[i]){
                    Max[i] = f[i][str[i]];
                    res[i] = str[i];
                    
                }

                else if(f[i][str[i]] == Max[i]){
                    res[i] = min(res[i], str[i]);
                }
            }
        }

        for(ll i = 0; i < n; i++){
            sum += m - Max[i];
            
        }

        for(ll i = 0; i < n; i++) cout << res[i];
        cout << "\n";
        cout << sum << "\n";
    }
    return 0;
}