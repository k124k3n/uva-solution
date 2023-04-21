#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>

bool comp(pair<ll, ll> a, pair<ll,ll> b){
    if(a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unordered_map<ll, ll> rl;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> pq(comp);
    string str;
    while(getline(cin, str) && str != "#"){
        vector<string> dt;
        stringstream ss(str);
        string temp;
        
        while(ss >> temp){
            dt.push_back(temp);
        }

        string com = dt[0];
        ll id = stoi(dt[1]);
        ll tm = stoi(dt[2]);
        rl[id] = tm;
        pq.push({id, tm});
    }

    ll k; cin >> k;

    while(k--){
        
        cout << pq.top().first << "\n";
        ll id = pq.top().first;
        ll tm = pq.top().second + rl[id];
        pq.pop();
        pq.push({id, tm});
    }

    return 0;
}