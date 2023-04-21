#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dt{
    ll tm, a, b;

    friend bool operator<(dt x, dt y){
        return x.tm < y.tm;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    ll cs = 0;
    while(cin >> n && n){
        cout << "Case " << ++cs << ": ";

        

        multiset<dt> wake, sl;
        bool found = false;
        for(ll i = 0; i < n; i++){
            ll a,b,c; cin >> a >> b >> c;
            if(c <= a) wake.insert({a-c+1,a,b});
            else sl.insert({(a+b)-c+1,a,b});
        }

        if(n==1 && wake.size()!=0){
            cout << 1 << "\n";
            continue;
        }

        for(ll i = 1; i <= 10000; i++){

            // cout << "before\nwake = {";
            // for(auto [tm, a, b]: wake) cout << tm << ", ";
            // cout << "}\n";
            // cout << "sleep = {";
            // for(auto [tm, a, b]: sl)cout << tm << ", ";
            // cout << "}\n";

            ll now = i;

            if(sl.size()==0){
                cout << i << "\n";
                found = true;
                break;
            }
            
            
            // if(wake.size()==0) now = (*sl.begin()).tm;
            // else now = min((*sl.begin()).tm, (*wake.begin()).tm);

            // ll ad = 0;
            // for(auto [tm,a,b]: sl){
            //     if(tm!=now) break;
            //     ++ad;
            // }

            // if((sl.size()-ad)==0){
            //     cout << now << "\n";
            //     found = true;
            //     break;
            // }

            

            if(sl.size() > wake.size()){ // sleep > wake
                
                ll tm = (*wake.begin()).tm;
                
                while(!wake.empty() && (*wake.begin()).tm==now){ // checking
                    ll a = (*wake.begin()).a;
                    ll b = (*wake.begin()).b;
                    sl.insert({tm+b, a, b});
                    wake.erase(wake.begin());
                }

                        
            }

            else{
                
                ll tm = (*wake.begin()).tm;
                
                while(!wake.empty() && (*wake.begin()).tm==now){ // checking
                    ll a = (*wake.begin()).a;
                    ll b = (*wake.begin()).b;
                    wake.erase((wake.begin()));
                    wake.insert({tm+a, a, b});
                }

            }

            // cout << now << "\n";
            while(!sl.empty() && (*sl.begin()).tm==now){ // baru bangun
                ll a = (*sl.begin()).a;
                ll tm = (*sl.begin()).tm;
                ll b = (*sl.begin()).b;
                wake.insert({tm+a, a, b});
                sl.erase(sl.begin());
            }

            

            // cout << "after\nwake = {";
            // for(auto [tm, a, b]: wake) cout << tm << ", ";
            // cout << "}\n";
            // cout << "sleep = {";
            // for(auto [tm, a, b]: sl)cout << tm << ", ";
            // cout << "}\n\n";
        }

        if(!found) cout << -1 << "\n";
    }
    return 0;
}