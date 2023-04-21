#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;
    ll cs = 0;
    while(cin >> n){
        priority_queue<ll, vector<ll>, greater<ll>> q;
        ll in_degree[n];
        for(ll i = 0; i < n; i++) in_degree[i] = 0;
        unordered_map<string, ll> key;
        vector<ll> adj[n];
        ll k = 0;
        vector<string> li;
        for(ll i = 0; i < n; i++){
            string temp; cin >> temp;
            key[temp] = k++;
            li.push_back(temp);
        }

        ll c; cin >> c;

        while(c--){
            string a, b; cin >> a >> b;
            ll ka = key[a], kb = key[b];
            adj[ka].push_back(kb);
            ++in_degree[kb];
        }

        for(ll i = 0; i < k; i++){
            if(in_degree[i]==0) q.push(i);
        }

        cout << "Case #" << ++cs << ": ";
        cout << "Dilbert should drink beverages in this order: ";
        while(!q.empty()){
            ll now = q.top(); q.pop();
            cout << li[now];
            for(auto x: adj[now]){
                --in_degree[x];
                if(in_degree[x]==0) q.push(x);
            }

            if(!q.empty()) cout << " ";
        }
        
        cout << ".\n\n";
    }
    return 0;
}