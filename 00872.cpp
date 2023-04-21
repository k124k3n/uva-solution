#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll in_degree[50]; // pass
vector<ll> adj[50]; // pass
vector<string> name; // pass
vector<string> ou; // pass
bool vis[50];
ll k;

void r(ll d){
    if(d==k){
        for(ll i = 0; i < k; i++){
            cout << ou[i];
            if(i!=k-1) cout << " ";
        }
        cout << "\n";
        return;
    }

    for(ll i = 0; i < k; i++){
        if(!vis[i] && in_degree[i]==0){
            ou.push_back(name[i]);
            for(auto x: adj[i]){
                --in_degree[x];
            }
            vis[i] = true;
            r(d+1);
            ou.pop_back();
            vis[i] = false;
            for(auto x: adj[i]){
                ++in_degree[x];
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    cin.ignore();
    string str; getline(cin, str);

    while(t--){
        k = 0;
        unordered_map<string, ll> key;
        name.clear();

        for(ll i = 0; i < 50; i++){
            in_degree[i] = 0;
            adj[i].clear();
        }

        
        getline(cin, str);
        stringstream ss(str); string temp;

        while(ss >> temp){
            name.push_back(temp);
        }

        sort(name.begin(), name.end());

        for(auto x: name){
            key[x] = k++;
        }

        getline(cin, str);
        stringstream ss1(str);
        ss << str;

        while(ss1 >> temp){
            // cout << temp[0] << " " << temp[2] << "\n";
            ll a = key[string(1, temp[0])];
            ll b = key[string(1, temp[2])];
            ++in_degree[b];
            
            adj[a].push_back(b); // added adj!
        }

        r(0);


        if(t) cout << "\n";

        // process spaces
        if(cin.good()) getline(cin, str);

    }
    return 0;
}