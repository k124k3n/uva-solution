#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string str;

    while(getline(cin, str)){
        cout << str << "\n";
        stringstream ss(str); string temp;
        vector<ll> li;
        ll fpb;
        while(ss >> temp){
            ll sum = 0;
            ll mul = 1;
            for(ll i = temp.length()-1; i >= 0; i--){
                sum += mul * (temp[i]-'a'+1);
                mul = (mul << 5);
            }
            li.push_back(sum);
            if(li.size()==1) fpb = li[0];
            else fpb = __gcd(fpb, sum);
            cout << sum << " ";
        }
        cout << "\n";

        sort(li.begin(), li.end(), greater<ll>());

        bool found = false;
        for(ll i = 0; i < li.size() && !found; i++){

            for(ll j = li[i]; j <= li[0]; j += li[i]){
                bool fB = true;
                unordered_map<ll, bool> hi;
                for(auto x: li){
                    ll hm = (j/x) % li.size();
                    if(hi[hm]){
                        fB = false;
                        break;
                    }
                    hi[hm] = true;
                }

                if(fB){
                    cout << j << "\n\n";
                    found = true;
                    break;
                }    
            }
        }

    }
    return 0;
}