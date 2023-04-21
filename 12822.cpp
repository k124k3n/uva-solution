#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll home = 0, guest = 0; // reset pls
map<string, ll> led;

struct dt{
    ll h,m,s;

    dt(ll _h, ll _m, ll _s){
        h = _h;
        m = _m;
        s = _s;
    }
};

ll total(ll h, ll m, ll s){
    return (3600*h+60*m+s);
}

ll check(ll hi){
    ll sum = 0;

    if(hi == 0) return 6;

    while(hi > 0){

        sum += led[to_string(hi%10)];
        hi /= 10;

    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    led["0"] = 6, led["1"] = 2, led["2"] = 5, led["3"] = 5, led["4"] = 4, led["5"] = 5, led["6"] = 6, led["7"] = 3, led["8"] = 7, led["9"] = 6;
    ll h, m, s; char spt;

    string st; ll cs = 0;
    vector<ll> sch; ll sum = 0;// reset pls
    while(cin >> st){
        
        cin >> h >> spt >> m >> spt >> s;
        sch.push_back(total(h,m,s));

        if(st == "START") continue;

        ll watt = check(home) + check(guest);
        sum += watt * (sch[sch.size()-1] - sch[sch.size()-2]);
        // cout << "sum += " << watt << " * " << (sch[sch.size()-1] - sch[sch.size()-2]) << "\n";

        if(st == "SCORE"){
            string who; ll score; cin >> who >> score;
            if(who == "home") home += score;
            else if(who == "guest") guest += score;
        }

        
        if(st == "END"){
            cout << "Case " << ++cs << ": " << sum << "\n";
            sum = 0;
            sch.clear();
            home = 0;
            guest = 0;
        }


        
    }
    return 0;
}