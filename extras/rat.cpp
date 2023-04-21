#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    random_device rd;

    default_random_engine generator(rd());
    uniform_int_distribution<ll> distribution(1, 6);
    uniform_int_distribution<ll> rdo(1, 30);
    uniform_int_distribution<ll> lang(1, 1000);
    ll n = rdo(generator), q = rdo(generator);

    cout << n << " " << q << "\n";
    for(ll i = 0; i < n; i++){
        cout << lang(generator);
        if(i!=(n-1)) cout << " ";
    } cout << "\n";

    for(ll i = 0; i < q; i++){
        uniform_int_distribution<ll> hm(0, 1);
        ll num = hm(generator);
        uniform_int_distribution<ll> hai(1, n);
        if(num){ // shift
            cout << "shift(";

            ll jml = distribution(generator);
            unordered_map<ll, bool> ada;
            vector<ll> v;
            for(ll j = 0; j < jml; j++){
                ll bil = hai(generator);
                
                while(ada.find(bil) != ada.end()){
                    bil = hai(generator);
                }

                ada[bil] = true;

                v.push_back(bil);
            }

            sort(v.begin(), v.end());

            for(ll j = 0; j < v.size(); j++){
                cout << v[j];
                if(j!=(v.size()-1)) cout << ",";
            }

            cout << ")\n";
        }

        else{
            cout << "query(";

            ll jml1 = hai(generator);
            ll jml2 = hai(generator);

            cout << min(jml1,jml2) << "," << max(jml1,jml2);

            cout << ")\n";
        }
    }

    
    return 0;
}