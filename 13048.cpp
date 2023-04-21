#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t; ll cs = 0;
    while(t--){
        cout << "Case " << ++cs << ": ";
        string str; cin >> str;
        ll sum = 0;
        bool vis[str.length()] = {0};

        for(ll i = 0; str[i]; i++){
            if(str[i] == 'D') vis[i] = true;
            if(str[i] == 'B'){
                for(ll j = i; j >= i-2 && j >= 0; j--){
                    vis[j] = true;
                }
            }
            if(str[i] == 'S'){
                for(ll j = i; j >= i-1 && j >= 0; j--){
                    vis[j] = true;
                }
                if(i+1 < str.length()) vis[i+1] = true;
            }
        }

        for(ll i = 0; i < str.length(); i++){
            if(!vis[i]) ++sum;
        }

        cout << sum << "\n";
    }
    return 0;
}