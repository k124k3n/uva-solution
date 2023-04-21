#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << fixed << setprecision(3);
    ll t; cin >> t;
    while(t--){
        unordered_map<char, ll> chemic;
        string str; cin >> str;
        for(ll i = 0; i < str.length(); i++){
            char catc = str[i];
            if(i < str.length()-1 && isdigit(str[i+1])){
                
                string angka = "";
                ++i;
                while(i < str.length() && isdigit(str[i])){
                    angka += str[i];
                    ++i;
                }
                --i;
                chemic[catc] += stoi(angka);
            }
            else ++chemic[catc];
        }

        double res = chemic['C']*12.01 + chemic['H']*1.008 + chemic['O']*16.00 + chemic['N']*14.01;
        cout << res << "\n";
    }
    return 0;
}