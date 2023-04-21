#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; ll cs = 0;
    while(cin >> n && n){
        cout << "Case " << ++cs << ":\n";
        vector<string> ram;
        string m; cin >> m;
        string prev = m;
        bool hv = false; // pernah cetak
        for(ll i = 0; i < n-1; i++){
            string str; cin >> str;

            if(stoi(str)-stoi(prev) != 1){ // reset
                hv = true;
                ll j = 0;
                while(m[j]==prev[j] && m[j])j++;
                if(j == m.length()) cout << m << "\n";
                else cout << m << "-" << prev.substr(j) << "\n";
                m = str;
            }

            prev = str;
        }
        
        ll j = 0;
        while(m[j]==prev[j] && m[j])j++;
        if(j == m.length()) cout << m << "\n";
        else cout << m << "-" << prev.substr(j) << "\n";
        
        cout << "\n";
    }
    return 0;
}