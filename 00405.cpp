#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dt{
    string mta, country, admd, prmd, on;

    dt(string _mta, string _country, string _admd, string _prmd, string _on){
        mta = _mta;
        country = _country;
        admd = _admd;
        prmd = _prmd;
        on = _on;
    }

};

map<string, vector<dt>> adj;
dt id = {"0", "0", "0", "0", "0"};
ll able = 0; // reset plz
map<string, bool> vis;

string dfs(string now){
    // cout << "visited " << now << "\n";
    if(vis[now]){
        able = -1;
        return now;
    }

    vis[now] = true;
    for(auto &[mta, country, admd, prmd, on]: adj[now]){
        ll cnt = 0;
        if((country == id.country) || country == "*") ++cnt;
        if((admd == id.admd) || admd == "*") ++cnt;
        if((prmd == id.prmd) || prmd == "*") ++cnt;
        if((on == id.on) || on == "*") ++cnt;

        if(cnt == 4){
            // cout << mta << " " << country << " " << admd << " " << prmd << " " << on << " " << "\n";
            if(mta == now){
                able = 1;
                return mta;
            }
            
            else return dfs(mta);
        }
    }

    able = 0;
    return now;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll m; ll cs = 0;
    while(cin >> m){
        cout << "Scenario # " << ++cs << "\n";
        while(m--){
            string ori; ll i; cin >> ori >> i;
            vector<dt> dum;
            while(i--){
                string mta, country, admd, prmd, on;
                cin >> mta >> country >> admd >> prmd >> on;
                adj[ori].emplace_back(mta, country, admd, prmd, on);
            }
        }

        ll n; cin >> n;

        for(ll i = 1; i <= n; i++){
            vis.clear();
            cout << i << " -- ";
            able = 0;

            string mta, country, admd, prmd, on;
            cin >> mta >> country >> admd >> prmd >> on;

            id = {mta, country, admd, prmd, on};

            string res = dfs(mta);

            // cout << hm.mta << "\n";
            if(able==1) cout << "delivered to " << res << "\n";
            else if(able == 0) cout << "unable to route at " << res << "\n";
            else cout << "circular routing detected by " << res << "\n";

        }

        cout << "\n";
        


    }
    return 0;
}