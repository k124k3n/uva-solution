#include <bits/stdc++.h>
using namespace std;

#define ll long long

unordered_map<char, ll> f({
    {'B', 1}, {'F', 1}, {'P', 1}, {'V', 1}, 
    {'C', 2}, {'G', 2}, {'J', 2}, {'K', 2}, {'Q', 2}, {'S', 2}, {'X', 2}, {'Z', 2}, 
    {'D', 3}, {'T', 3}, 
    {'L', 4}, 
    {'M', 5}, {'N', 5}, 
    {'R', 6}, 
});

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    string str;

    while(cin >> str){

        string res;

        for(ll i = 0; str[i]; i++){
            char c = '0' + f[str[i]];
            
            if(f[str[i]]){
                if(i>=1 && f[str[i]] == f[str[i-1]]) continue;
                res += string(1, c);
            }

        }

        cout << res << "\n";
    }


    return 0;
}
