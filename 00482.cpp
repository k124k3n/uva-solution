#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    cin.ignore(100, '\n');
    for(ll x = 0; x < t; x++){
        if(x!=0) cout << "\n";
        unordered_map<ll, ll> hi;
        ll k = 0;
        vector<string> li;
        string dum; getline(cin, dum);
        string s; getline(cin, s);
        stringstream ss(s); string temp;
        while(ss >> temp){
            hi[stoi(temp)-1] = k++;
        }

        getline(cin, s);

        stringstream ss2(s);

        while(ss2 >> temp){
            li.push_back(temp);
        }

        for(ll i = 0; i < k; i++){
            cout << li[hi[i]] << "\n";
        }

    }
    return 0;
}