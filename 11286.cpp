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
        unordered_map<string, ll> f;
        ll Max = LLONG_MIN;
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            string str; getline(cin, str);
            stringstream ss(str); string temp;
            vector<string> v;

            while(ss >> temp){
                v.push_back(temp);
            }

            sort(v.begin(), v.end());

            string ky;

            for(auto x: v){
                ky += x + " ";
            }

            Max = max(Max, ++f[ky]);
            
        }

        for(auto &[key, val]: f){
            if(val==Max) sum += Max;
        }

        cout << sum << "\n";

    }
    return 0;
}