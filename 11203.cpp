#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;

    for(ll i = 0; i < n; i++){
        ll ei = 0, mi = 0;
        string str; cin >> str;
        bool ter = true;
        unordered_map<char,ll> f;
        for(ll j = 0; j < str.length(); j++){
            ++f[str[j]];

            if(str[j] == 'E') ei = j;
            if(str[j] == 'M') mi = j;

            if(str[j] != '?' && str[j] != 'M' && str[j] != 'E'){
                ter = false;
                break;
            }



        }

        ll A = mi;
        ll B = (ei-1)-mi;
        ll C = str.length()-1-ei;

        // cout << A << " " << B << " " << C << "\n";
        bool a = f['M']==1 && f['E']==1 && f['?'] >= 4 && (mi+1) < ei && mi > 0 && (C-B)==A;

        if(ter&&a) cout << "theorem\n";
        else cout << "no-theorem\n";
    }
    return 0;
}