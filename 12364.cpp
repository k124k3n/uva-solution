#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<char, vector<string>> dc({
    {'0', {
        ".*",
        "**",
        "..",
    }},

    {'1', {
        "*.",
        "..",
        "..",
    }},

    {'2', {
        "*.",
        "*.",
        "..",
    }},

    {'3', {
        "**",
        "..",
        "..",
    }},

    {'4', {
        "**",
        ".*",
        "..",
    }},

    {'5', {
        "*.",
        ".*",
        "..",
    }},

    {'6', {
        "**",
        "*.",
        "..",
    }},

    {'7', {
        "**",
        "**",
        "..",
    }},

    {'8', {
        "*.",
        "**",
        "..",
    }},

    {'9', {
        ".*",
        "*.",
        "..",
    }},

});

map<string, char> dcb({
    {".***..", '0'},
    {"*.....", '1'},
    {"*.*...", '2'},
    {"**....", '3'},
    {"**.*..", '4'},
    {"*..*..", '5'},
    {"***...", '6'},
    {"****..", '7'},
    {"*.**..", '8'},
    {".**...", '9'},
});

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;

    while(cin >> n && n){
        char p; cin >> p;

        if(p == 'S'){
            string str; cin >> str;
            
            for(ll i = 0; i < 3; i++){
                for(ll j = 0; j < n; j++){
                    cout << dc[str[j]][i];
                    if(j!=n-1) cout << " ";
                }
                cout << "\n";
            }
        }

        else{
            string ars[3];
            cin.ignore(1000, '\n');
            for(ll i = 0; i < 3; i++){
                getline(cin, ars[i]);
            }


            for(ll i = 0; i < ars[0].length(); i += 3){
                string ga;
                for(ll j = 0; j < 3; j++){
                    for(ll k = i; k <= i+1; k++){
                        ga += string(1, ars[j][k]);
                    }
                }
                cout << dcb[ga];
            } cout << "\n";

            

        }
    }
    return 0;
}