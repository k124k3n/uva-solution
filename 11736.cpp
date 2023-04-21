#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ull n, v;
    while(cin >> v >> n){
        string a; ull b; vector<pair<string,ull>> usage; map<string, ull> final;
        for(ll i = 0; i < n; i++){
            cin >> a >> b;
            usage.push_back(make_pair(a,b));
        }

        for(auto x: usage){
            string temp = "";
            ull res = 0;
            for(ull i = 0; i < x.second; i++){
                string hi; cin >> hi;
                temp += hi;
            }

            reverse(temp.begin(), temp.end());

            for(ll i = temp.length()-1; i >= 0; i--){
                ull pangkat = pow(2, i);
                if(temp[i] != '0') res += pangkat;
                
            }

            final[x.first] = res;
            
        }

        ull h; cin >> h;
        for(ull i = 0; i < h; i++){
            string hi; cin >> hi;
            cout << hi << "=";
            if(final.find(hi) != final.end()){
                cout << final[hi];
            }
            cout << "\n";
        }

    }
    return 0;
}