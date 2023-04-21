#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sll pair<string, ll>


bool comp(sll a, sll b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;
    while(t--){
        cin.ignore(1000, '\n');
        bool found = true;
        string title; getline(cin, title);

        for(ll i = 0; title[i]; i++){
            if(isalpha(title[i])) title[i] = toupper(title[i]);
        }

        ll m,n,b; cin >> m >> n >> b;
        unordered_map<string, ll> p;
        vector<sll> hi;

        for(ll i = 0; i < m; i++){
            string ing; ll pr; cin >> ing >> pr;
            p[ing] = pr;
        }

        for(ll i = 0; i < n; i++){
            cin.ignore(1000, '\n');
            string rtitle; getline(cin, rtitle);
            ll k; cin >> k;
            ll sum = 0;
            
            for(ll j = 0; j < k; j++){
                string ing; ll pr; cin >> ing >> pr;
                sum += p[ing]*pr;
            }

            
            
            if(sum <= b){
                hi.emplace_back(rtitle, sum);
            }
        }

        cout << title << "\n";
        if(hi.size()==0) cout << "Too expensive!\n\n";
        else{
            sort(hi.begin(), hi.end(), comp);
            for(auto &[ing, pr]: hi){
                cout << ing << "\n";
            }

            cout << "\n";
        }

    }
    return 0;
}