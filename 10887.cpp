#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; ll cs = 0;
    while(cin >> t){
        ll cs = 0;
        while(t--){
            ll m,n; cin >> m >> n;
            cin.ignore(1000, '\n');
            string A[m], B[n];
            set<string> C;
            for(ll i = 0; i < m; i++){
                getline(cin, A[i]);
            }

            for(ll i = 0; i < n; i++){
                getline(cin, B[i]);
            }

            for(ll i = 0; i < m; i++){
                for(ll j = 0; j < n; j++){
                    string hi = A[i] + B[j];
                    C.insert(hi);
                }
            }

            cout << "Case " << ++cs << ": " << C.size() << "\n";
        }
        


    }
    return 0;
}