#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;

    while(cin >> n && n){
        cin.ignore(100, '\n');
        ll msum = LLONG_MIN;
        vector<ll> s;
        ll tot = 0;
        while(n--){
            string str; getline(cin, str);
            ll sum = 0;
            for(ll i = 0; i < str.length(); i++){
                sum += (str[i] == 'X');
            }

            msum = max(msum, sum);
            s.push_back(sum);
        }

        for(auto x: s){
            tot += msum - x;
        }

        cout << tot << "\n";
    }
    return 0;
}
