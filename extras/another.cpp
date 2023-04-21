#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        unordered_map<ll, ll> A;

        ll K; cin >> K;
        for (ll i = 1; i <= K; i++) {
            char ch; ll val;
            cin >> ch >> val;

            A[(ll)ch] = val;
        }

        ll M; cin >> M;
        cin.ignore(1000, '\n');
        double res = 0;
        for (ll i = 1; i <= M; i++) {
            string line;
            getline(cin, line);
            for (auto& ch : line) {
                res += A[ch];
            }
        }

        res /= 100;

        
        
        cout << fixed << setprecision(2) << res << "$\n";
    }
    
    return 0;
}

/*
1
1
a 1
1
bbbbbbb
*/