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
 
        cout << "Case #" << ++cs << "\n";
        ll n,m; cin >> n;
        string mt[n];

        for(ll i = 0; i < n; i++) cin >> mt[i];

        cin >> m;

        for(ll k = 0; k < m; k++){
            string cm; cin >> cm;

            if(cm == "row"){
                ll a,b; cin >> a >> b;
                --a, --b;

                swap(mt[a], mt[b]);
            }

            else if(cm == "col"){
                ll a, b; cin >> a >> b;
                string p, q;
                --a, --b;

                for(ll i = 0; i < n; i++){
                    swap(mt[i][a], mt[i][b]);
                }
            }

            else if(cm == "inc"){
                for(ll i = 0; i < n; i++){
                    for(ll j = 0; j < n; j++){
                        ll hm = ((mt[i][j] - '0') + 1)%10;
                        char g = '0' + hm;
                        mt[i][j] = g;
                    }
                }
            }

            else if(cm == "dec"){
                for(ll i = 0; i < n; i++){
                    for(ll j = 0; j < n; j++){
                        ll hm = ((mt[i][j] - '0') + 19)%10;
                        char g = '0' + hm;
                        mt[i][j] = g;
                    }
                }
            }

            else if(cm == "transpose"){
                char cp[n][n];

                for(ll i = 0; i < n; i++){
                    for(ll j = 0; j < n; j++){
                        cp[i][j] = mt[j][i];
                    }
                }

                for(ll i = 0; i < n; i++){
                    for(ll j = 0; j < n; j++){
                        mt[i][j] = cp[i][j];
                    }
                }
            }
        }

        for(ll i = 0; i < n; i++){
            cout << mt[i] << "\n";
        }

        cout << "\n";
    }
    return 0;
}