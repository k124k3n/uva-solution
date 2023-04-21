#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll m, n;
    while(cin >> m >> n){
        unordered_map<ll, vector<ll>> adj, pos;

        for(ll i = 0; i < m; i++){
            ll k; cin >> k;
            vector<ll> l;
            for(ll j = 0; j < k; j++){
                ll temp; cin >> temp;
                l.push_back(temp);
                
            }

            for(ll j = 0; j < k; j++){
                ll temp; cin >> temp;
                adj[l[j]].push_back(temp);
                pos[l[j]].push_back(i+1);
            }
        }

        cout << n << " " << m << "\n";
        for(ll i = 0; i < n; i++){
            if(adj[i+1].size()==0){
                cout << "0\n\n";
                continue;
            }

            cout << pos[i+1].size() << " ";
            for(ll j = 0; j < pos[i+1].size(); j++){
                cout << pos[i+1][j];

                if(j!=(pos[i+1].size()-1)) cout << " ";
            } cout << "\n";

            for(ll j = 0; j < adj[i+1].size(); j++){
                cout << adj[i+1][j];

                if(j!=(adj[i+1].size()-1)) cout << " ";
            } cout << "\n";
        }
    }
    return 0;
}