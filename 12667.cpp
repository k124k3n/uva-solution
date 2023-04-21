#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n,t,m; cin >> n >> t >> m;
    ll MaxC = -1;
    map<string, bool> stat[t+1];
    ll Max[13]; ll team[13];

    for(ll i = 0; i <= 12; i++) Max[i] = -1;

    for(ll i = 0; i < m; i++){
        ll tm, id; string prob, verd; cin >> tm >> id >> prob >> verd;
        ll num = prob[0] - 'A';

        MaxC = max(MaxC, num);
        if(stat[id][prob] == 0 && verd == "Yes"){
            
            if(tm > Max[num]){
                Max[num] = tm;
                team[num] = id;
            }

            else if(tm == Max[num]) team[num] = id;
        }

        if(verd == "Yes") stat[id][prob] = 1;

    }

    for(ll i = 0; i <= MaxC; i++){
        char c = 'A' + i;

        cout << c << " ";

        if(Max[i] == -1) cout << "- -\n";
        else{
            cout << Max[i] << " " << team[i] << "\n";
        }
    }

    return 0;
}