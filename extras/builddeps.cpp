#include <bits/stdc++.h>
using namespace std;

#define ll long long

unordered_map<string, ll> in_degree;
unordered_map<string, vector<string>> adj;
queue<string> pq;
stack<string> dum;
unordered_set<string> li;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    cin.ignore();
    while(t--){
        string str; getline(cin, str);
        stringstream ss(str); ll cs = 0; string temp;
        
        ss >> temp;
        string ch = temp; ch.pop_back();
        li.insert(ch);
        while(ss >> temp){
            li.insert(temp);
            ++in_degree[ch];
            adj[temp].push_back(ch);
        }
    }

    string vis; cin >> vis;
    unordered_map<string, bool> visited;
    pq.push(vis);
    visited[vis] = true;

    for(auto x: li){
        if(in_degree[x]==0 && x!=vis) dum.push(x);
    }

    while(!dum.empty()){
        string now = dum.top(); dum.pop();

        for(auto x: adj[now]){
            --in_degree[x];
        }

    }

    while(!pq.empty()){
        string now = pq.front(); pq.pop();
        cout << now << "\n";
        for(auto x: adj[now]){
            if(!visited[x]){
                pq.push(x);
                visited[x] = true;
            }
        }

    }
    return 0;
}