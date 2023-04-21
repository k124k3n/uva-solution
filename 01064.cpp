#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, m;

    ll cs = 0;
    while(cin >> n >> m && n){
        cout << "Case " << ++cs << ": ";
        ll msz = 0;
        ll sz = 0;
        set<ll> pack[n+1];
        set<ll> buff[n+1];
        for(ll i = 1; i <= n; i++){
            ll temp; cin >> temp;
            for(ll j = 1; j <= temp; j++){
                pack[i].insert(j);
            }
        }


        while(m--){
            ll name, st, en; cin >> name >> st >> en;

            for(ll i = 1; i <= n; i++){
                while(buff[i].size()!=0 && *buff[i].begin() == *pack[i].begin()){
                    ll fc = *pack[i].begin();
                    buff[i].erase(fc);
                    pack[i].erase(fc);
                    --sz;
                }
            }
            

            if(st != *pack[name].begin()){
                for(ll i = st; i <= en; i++){
                    buff[name].insert(i);
                    ++sz;
                    msz = max(sz, msz);
                }
            }

            else{
                for(ll i = st; i <= en; i++){
                    pack[name].erase(i);
                }
            }

        }

        cout << msz << "\n\n";
    }
    return 0;
}