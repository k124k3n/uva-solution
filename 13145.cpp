#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;
    while(cin >> n && n!=0){
        cin.ignore(1000, '\n');
        string str; getline(cin, str);
        ll got = (n+(26*999))%26;

        // cout << got << " SLEBEW!\n";
        for(ll i = 0; str[i]; i++){
            if(!(isalpha(str[i]))) continue;
            if(tolower(str[i]) == str[i]){
                ll hi = (((str[i]-'a'+got)%26));
                // cout << hi << "\n";
                char k = 'a' + hi;

                str[i] = k ;
            }
            else{
                ll hi = ((str[i]-'A'+got)%26);
                char k = 'A' + hi;
                // cout << hi << "\n";
                str[i] = k;
            }

            // cout << str[i] << "HI! ";
        } // cout << "\n";

        cout << str << "\n";

    }
    
    return 0;
}