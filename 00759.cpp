#include <bits/stdc++.h>
using namespace std;

#define ll long long

// I=1, V=5, X=10, L=50, C=100, D=500, and M=1000, IV=4, IX=9, XL=40, XC=90, CD=400, CM=900.;

map<char, ll> rom({
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    });

vector<pair<string, ll>> conv({
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, 
        {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
});

map<string, ll> mconv({
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, 
        {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
});

string AtoR(ll res){
    string temp;
    for(auto &[hi, val]: conv){
        // cout << res << " " << val << "\n";
        while(res >= val){
            temp += hi;
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
    string str;
    
    while(getline(cin, str)){
        if(str == ""){
            cout << 0 << "\n";
            continue;
        }
        ll res = 0; ll MaxS = LLONG_MIN;

        bool not_valid = false;

        for(ll i = 0; str[i]; i++){
            if(str[i+1] && (rom[str[i]] < rom[str[i+1]])){
                string temp = string(1, str[i]) + string(1, str[i+1]);
                if(mconv.find(temp) == mconv.end()) not_valid = true;

                res += rom[str[i+1]] - rom[str[i]];

                i++;
            }

            else res += rom[str[i]];
        }

        ll streak = 1;
        for(ll i = 1; str[i]; i++){
            if(str[i] == str[i-1]) ++streak;
            else streak = 1;
            MaxS = max(MaxS, streak);
        }
        
        if(not_valid||MaxS>=4|| str != AtoR(res)) cout << "This is not a valid number\n";
        else cout << res << "\n";


    }
    return 0;
}