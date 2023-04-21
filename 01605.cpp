#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    while(cin >> n){
        cout << 2 << " " << n << " " << n << "\n";
        
        char itr = 'A';

        for(ll p = 0; p < n; p++){ // horizontal one
            ll i = 1;

            itr = 'A';
            for(; i <= 26 && i <= n; i++){
                cout << itr;
                ++itr;
            } 

            itr = 'a';
            for(; i <= 52 && i <= n; i++){
                cout << itr;
                ++itr;
            }
            cout << "\n";
        } cout << "\n";

        itr = 'A';


        
        ll i = 1;
        for(; i <= 26 && i <= n; i++){ // vert 1

            for(ll j = 0; j < n; j++){
                cout << itr;
            } cout << "\n";

            ++itr;
        }

        itr = 'a';

        for(; i <= 52 && i <= n; i++){ // vert 2

            for(ll j = 0; j < n; j++){
                cout << itr;
            } cout << "\n";

            ++itr;
        }
        
        

        

        // if(cin.good()) cout << "\n";
    }
    return 0;
}