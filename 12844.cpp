#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<ll> w;
    w.assign(10, 0);

    ll t; cin >> t;
    ll cs = 0;
    while(t--){
        bool found = false;
        ll sum = 0;

        for(ll i = 0; i < 10; i++){
            cin >> w[i];
            sum += w[i];
        }

        sum /= 4;

        ll arr[5];

        
        for(ll a = 1; (w[0]-a) >= a && !found; a++){
            ll b = w[0]-a;
            arr[0] = a; arr[1] = b;
            for(ll d = b; (w[9]-d) >= d && !found; d++){
                ll e = w[9] - d;
                arr[3] = d; arr[4] = e;
                ll c = sum - a - b - d - e;
                // cout << c << "\n";
                if(c < b || c > d) continue;
                arr[2] = c;
                // now brute!
                vector<ll> test;
                for(ll i = 0; i < 5 && !found; i++){
                    for(ll j = i+1; j < 5 && !found; j++){
                        test.push_back(arr[i]+arr[j]);
                    }
                }

                sort(test.begin(), test.end());

                if(test==w){
                    found = true;

                    cout << "Case " << ++cs << ": ";
                    for(ll k = 0; k < 5; k++){
                        cout << arr[k];
                        if(k!=4) cout << " ";
                    }

                    cout << "\n";
                }
            
            }
        }
    }

    return 0;
}