#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<string, ll>> conv ({
    {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
    {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1},
});

map<char, ll> korek({
    {'M', 4}, {'D', 3}, {'C', 2}, {'L', 2}, {'X', 2}, {'V', 2}, {'I', 1},
});

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll n;

    while(cin >> n){
        string temp;

        for(auto &[rom, val]: conv){
            while(n >= val){
                temp += rom;
                n -= val;
            }
        }

        ll final = 0;

        for(ll i = 0; temp[i]; i++){
            final += korek[temp[i]];
        }

        cout << final << "\n";
    }
    return 0;
}