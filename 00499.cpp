#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;

    while(getline(cin, str)){
        ll f[200] = {0};
        vector<pair<ll,ll>> hi;

        for(ll i = 0; str[i]; i++){
            if(isalpha(str[i])) ++f[str[i]- 'A'];
        }

        for(ll i = 'A'; i <= 'z'; i++){
            if(isalpha((char) i)) hi.push_back({f[i - 'A'], i});
        }

        sort(hi.rbegin(), hi.rend());

        ll itr = 0;
        string res;

        while(itr < hi.size() && hi[itr].first == hi[0].first){
            res += string(1, (char)hi[itr].second);
            ++itr;
        }

        reverse(res.begin(), res.end());

        cout << res << " " << hi[0].first << "\n";
    }
    return 0;
}