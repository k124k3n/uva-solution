#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;

    while(t--){
        string str;
        unordered_map<char, bool> hi;
        ll gone = 0;
        ll edg = 0;
        while(cin >> str && str[0] != '*'){
            if(str[1]==str[3]) continue;
            if(!hi[str[1]]) ++gone;
            if(!hi[str[3]]) ++gone;

            hi[str[1]] = true; hi[str[3]] = true;
            ++edg;
        }

        string v; cin >> v; ll sum = 0;

        for(ll i = 0; v[i]; i++){
            if(v[i]==',') ++sum;
        }

        ll CC = (sum+1)-edg;

        cout << "There are " << CC - ((sum+1)-gone) << " tree(s) and " << (sum+1)-gone << " acorn(s).\n";
        
        


    }
    return 0;
}