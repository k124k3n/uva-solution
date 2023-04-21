#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sll pair<string, ll>

vector<sll> conv({
    {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10},
    {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1},
});

string AtoR(ll res){
    string temp;
    for(auto &[rom, val]: conv){
        while(res >= val){
            temp += rom;
            res -= val;
        }
    }

    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    string list[5] = {"I", "V", "X", "L", "C"};

    map<string, ll> dp[200];
    for(auto x: list) dp[0][x] = 0;
    for(ll i = 1; i <= 101; i++){
        for(auto x: list) dp[i][x] = dp[i-1][x];
        string p = AtoR(i);
        // cout << p << "\n";
        for(auto x: p) ++(dp[i][string(1, x)]);
    }

    while(cin >> n && n){
        cout << n << ": ";
        for(ll i = 0; i < 5; i++){
            cout << dp[n][list[i]] << " " << (char) tolower((char)list[i][0]);
            if(i!=4) cout << ", ";

        }


        cout << "\n";
    }
    return 0;
}