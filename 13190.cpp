#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sll pair<string, ll>

unordered_map<string, ll> prio;

bool comp(sll a, sll b){
    if(a.second!=b.second) return a.second > b.second;
    else return prio[a.first] > prio[b.first];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;
    ll n,k;

    
    while(t--){
        prio.clear();
        unordered_map<string, ll> f;

        priority_queue<sll, vector<sll>, function<bool(sll, sll)>> pq(comp);

        cin >> n >> k;

        for(ll i = 0; i < n; i++){
            string id; ll freq;
            cin >> id >> freq;
            prio[id] = i;
            f[id] = freq;
            pq.push({id, freq});
        }


        while(k--){
            auto [id, freq] = pq.top();
            ll r = freq + f[id];
            cout << freq << " " << id << "\n";
            pq.pop();
            pq.push({id, r});
        }
    }
    return 0;
}