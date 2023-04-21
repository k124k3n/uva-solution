#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    for(ll i = 1; i <= t; i++){

        cout << "Expression #" << i << ": ";
        map<string, string> hi;

        ll n; cin >> n;
        cin.ignore(1000, '\n');
        string last;
        for(ll i = 0; i < n; i++){
            string str; getline(cin, str);
            ll eq = str.find("=");
            
            // extract var name
            string var = str.substr(0, eq);
            
            var.pop_back();           
            last = var;
            string right = str.substr(eq+1);
            stringstream ss(right); string temp;
            string res;

            while(ss >> temp){
                if(isalpha(temp[0])){
                    res += hi[temp];
                    continue;
                }

                res += temp;
            }

            hi[var] = "(" + res + ")";

            
        }

        hi[last].pop_back();

        cout << hi[last].substr(1) << "\n";
    }


    return 0;
}