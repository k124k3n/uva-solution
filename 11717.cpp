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
        ll n, in, k; cin >> n >> in >> k;
        vector<ll> arr; 
        bool active = true;
        ll ina = 0, ign = 0, at = in;

        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            arr.push_back(temp);
        }

        for(ll i = 0; i < arr.size(); i++){
            if(arr[i] < at){ // still active
                at = arr[i] + in;
            }
            
            else{ // inactive
                ++ina;
                ll boot = arr[i] + k;
                ++i;

                while(i < arr.size() && arr[i] < boot){
                    ++ign;
                    ++i;
                }

                at = boot+in; // it finally active till boot+in
                --i;
            }
        }

        cout << ina << " " << ign << "\n";
    }

    return 0;
}