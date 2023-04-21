#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool comp(pair<ll, ll> a, pair<ll,ll> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < a.second;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t; ll cs = 0;
    while(t--){
        cout << "Case #" << ++cs << ":\n";
        unordered_map<ll, ll> freq;
        vector<ll> arr[3], real[3];
        vector<pair<ll,ll>> rank;
        for(ll p = 0; p < 3; p++){

            ll s; cin >> s;

            
            for(ll i = 0; i < s; i++){
                ll temp; cin >> temp;
                arr[p].push_back(temp);
                ++freq[temp];
            }

            sort(arr[p].begin(), arr[p].end());
        }

        for(ll p = 0; p < 3; p++){
            ll sum = 0;
            for(auto x: arr[p]){
                if(freq[x]==1){
                    real[p].push_back(x);
                    ++sum;
                }
            }

            rank.push_back({sum, p});
        }

        sort(rank.begin(), rank.end(), comp);

        for(auto &[sum, id]: rank){
            if(sum != rank[0].first) break;

            cout << id+1 << " " << real[id].size();
            if(real[id].size() != 0) cout << " ";

            for(ll i = 0; i < real[id].size(); i++){
                cout << real[id][i];
                if(i != real[id].size()-1) cout << " ";
            }

            cout << "\n";
        }

        

    }
    return 0;
}