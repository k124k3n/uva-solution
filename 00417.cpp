#include <bits/stdc++.h>
using namespace std;

#define ll long long

unordered_map<string, ll> dp;

string last;

void brute(ll now, ll d, string str){
    if(now==d){
        dp[str] = dp[last]+1;
        last = str;
    }

    else{
        for(char i = (str.length()==0)?'a': *(str.rbegin())+1; i <= 'z'; i++){
            str += string(1, i);
            brute(now+1, d, str);
            str.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    last = ".";
    dp["."] = 0;

    for(ll i = 1; i <= 5; i++){
        brute(0, i, "");
    }


    string str;

    while(cin >> str){
        cout << dp[str] << "\n";
    }

    return 0;
}