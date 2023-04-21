#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll sum = 0;
set<char> hm;
string a; ll cc,cw;
set<string> hi;
map<char, ll> freq;

void brute(ll depth, ll c, string temp = ""){
    // cout << temp << " " << depth << " " << c << "\n";
    if(c>cc) return;
    else if(depth==a.length()){
        if(c==cc) {
            ll w = 0;
            map<char, ll> freq2(freq);

            for(ll i = 0; i < temp.length(); i++){
                if(temp[i] != a[i] && freq2[temp[i]] > 0){
                    ++w;
                    --freq2[temp[i]];
                }
            }

            if(w == cw){
                cout << temp << "\n";
                hi.insert(temp);
            }

        }
    }
    else{
        for(char g = '1'; g <= '9'; g++){
            // cout << "a[" << depth << "] == " << g << " && freq[" << g << "] == " << freq[g] << "\n";
            if(a[depth] == g && freq[g] > 0){
                --freq[g];
                brute(depth+1, c+1, temp+g);
                ++freq[g];
            }
            
            else brute(depth+1, c, temp+g);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        hm.clear(), hi.clear(), freq.clear();

        cin >> a >> cc >> cw;
        for(ll i = 0; i < a.length(); i++){
            hm.insert(a[i]);
            ++freq[a[i]];
        }

        brute(0,0);

        // for(auto x: hi){
        //     cout << " " << x;
        // }
        // cout << "\n";

        cout << hi.size() << "\n";

    }   
    return 0;
}