#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;

    while(n--){

        unordered_map<char, ll> f;

        ll k, m; cin >> k;

        for(ll i = 0; i < k; i++){
            char c; ll g; cin >> c >> g;
            f[c] = g;
            cout << c << "\n";
        }

        cin >> m;
        cin.ignore(1000, '\n');

        double sum = 0;
        for(ll i = 0; i < m; i++){
            string str; getline(cin, str);
            // cout << str << "\n";
            for(ll j = 0; str[j]; j++){
                sum += f[str[j]];
            }
        }

        sum /= 100;

        cout << fixed << setprecision(2) << sum << "$\n";
    }
    return 0;
}