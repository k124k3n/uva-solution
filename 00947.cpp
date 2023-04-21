#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll sum = 0;
set<char> hm;
string a; ll cc,cw;
set<string> hi;

void brute(ll depth, ll c, string temp = ""){
    
    if(c>cc) return;
    else if(depth==a.length()){
        if(c==cc) {
            ll w = 0;
            bool result = true;
            map<char, ll> freqq;
            map<char, ll> freq;
            for(ll i = 0; i < temp.length(); i++){
                if(temp[i] != a[i]) ++freq[a[i]];
                if(temp[i] != a[i] && hm.find(temp[i]) != hm.end()){
                    ++w;
                    ++freqq[temp[i]];
                }
            }

            for(ll i = 0; i < temp.length(); i++){
                if(temp[i] != a[i] && freqq[temp[i]] != freq[temp[i]]){
                    result = false;
                    break;
                }
            }
            if(w == cw && result) hi.insert(temp);

        }
    }
    else{
        for(char g = '1'; g <= '9'; g++){
            if(a[depth] == g){
                hm.erase(g);
                brute(depth+1, c+1, temp+g);
                hm.insert(g);
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
        hm.clear(), hi.clear();
        cin >> a >> cc >> cw;
        for(ll i = 0; i < a.length(); i++){
            hm.insert(a[i]);
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