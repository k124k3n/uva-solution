#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dt{
    string plat; string epoch; string stat; ll now;

    dt(string _plat, string _epoch, string _stat, ll _now){
        plat = _plat;
        epoch = _epoch;
        stat = _stat;
        now = _now;
    }
};

bool comp(dt a, dt b){
    return a.epoch < b.epoch;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;
    getline(cin, str); getline(cin, str);

    ll tm[24];
    vector<dt> li;
    
    unordered_map<string, ll> inTime, sum, trip, day, vis;
    set<string> val;
    ll sp = 0;
    while(getline(cin, str)){
        // cout << str << "\n";
        stringstream ss(str); string temp;
        vector<string> l;
        while(ss >> temp){
            l.push_back(temp);
        }

        if(l.size()==24){
            for(ll i = 0; i < 24; i++){
                tm[i] = stoi(l[i]);
            }
        }

        else if(l.size() == 4){
            string plat = l[0];
            string epoch = l[1];
            string stat = l[2];
            ll tt = stoi(l[3]);

            li.emplace_back(plat, epoch, stat, tt);

        }

        else if(l.size()==0){ // processing
            // cout << sp << "\n";
            if(++sp != 1) cout << "\n";
            sort(li.begin(), li.end(), comp);
            for(auto &[plat, epoch, stat, tt]: li){
                if(stat == "enter"){
                    inTime[plat] = tt;
                    ll hour = 10*(epoch[6]-'0') + (epoch[7] - '0');
                    day[plat] = hour;
                    vis[plat] = true;
                }

                else{
                    if(!vis[plat]) continue;
                    
                    ll pay = abs(tt - inTime[plat]) * tm[day[plat]];
                    
                    ++trip[plat];
                    sum[plat] += pay;
                    inTime[plat] = -1;
                    vis[plat] = false;
                    val.insert(plat);
                }
            }

            for(auto x: val){
                cout << x << fixed << setprecision(2) <<  " $" << (double)(sum[x]+(trip[x]*100)+200)/100 << "\n";
            }

            li.clear(); inTime.clear(); sum.clear(); trip.clear(); val.clear(); vis.clear();
        }
    }

    if(++sp != 1) cout << "\n";   
    sort(li.begin(), li.end(), comp);
    for(auto &[plat, epoch, stat, tt]: li){
        // cout << plat << " " << epoch << " " << stat << " " << tt << "\n";
        if(stat == "enter"){
            inTime[plat] = tt;
            ll hour = 10*(epoch[6]-'0') + (epoch[7] - '0');
            day[plat] = hour;
            vis[plat] = true;
        }

        else{
            if(!vis[plat]) continue;
            // cout << plat << " " << inTime[plat] << "\n";
            ll pay = abs(tt - inTime[plat]) * tm[day[plat]];
            
            ++trip[plat];
            sum[plat] += pay;
            inTime[plat] = -1;
            vis[plat] = false;
            val.insert(plat);
        }
    }
    for(auto x: val){
        cout << x << fixed << setprecision(2) <<  " $" << (double)(sum[x]+(trip[x]*100)+200)/100 << "\n";
    }
    return 0;
}