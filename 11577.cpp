#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll m; cin >> m;

    cin.ignore(100, '\n');

    for(ll i = 0; i < m; i++){
        ll f[200] = {0};
        vector<pair<ll,ll>> hi;
        string str; getline(cin, str);

        for(ll j = 0; str[j]; j++){
            if(isalpha(str[j])) ++f[tolower(str[j])];
        }

        for(ll j = 'a'; j <= 'z'; j++){
            if(f[j]){
                hi.push_back({f[j], j});
                // cout << f[j] << " " << (char)j << "\n";
            }
        }

        sort(hi.rbegin(), hi.rend());

        ll itr = 0;
        string res;
        while(itr < hi.size() && hi[0].first==hi[itr].first){
            res += string(1, (char)hi[itr].second); 
            itr++;
        }

        sort(res.begin(), res.end());

        cout << res << "\n";
    }
    return 0;
}