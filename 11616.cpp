#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<string, ll>> conv({
    {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50},
    {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5},  {"IV", 4}, {"I", 1},
});

map<char, ll> mconv({
    {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
    {'X', 10}, {'V', 5}, {'I', 1},
});


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;
    while(cin >> str){
        if(isdigit(str[0])){
            ll res = stoi(str);
            string temp;

            for(auto &[rom, val]: conv){
                while(res >= val){
                    temp += rom;
                    res -= val;
                }
            }

            cout << temp << "\n";
        }

        else{
            ll res = 0;
            for(ll i = 0; str[i]; i++){
                if(str[i+1]&& mconv[str[i]] < mconv[str[i+1]]){
                    res += mconv[str[i+1]] - mconv[str[i]];
                    i++;
                }

                else res += mconv[str[i]];

                
            }

            cout << res << "\n";
        }
    }
    return 0;
}