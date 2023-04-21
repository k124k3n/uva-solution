#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    string s1, s2;

    while(cin >> s1 >> s2){
        if(s1.length() < s2.length()) swap(s1, s2);
        vector<ll> l;
   
        bool found = true;
        if((ll)s1.find("2")==-1 || (ll)s2.find("2")==-1){
            cout << max(s1.length(), s2.length()) << "\n";
            continue;
        }

        if((ll)s1.find("1")==-1 && (ll)s2.find("1")==-1 ){
            cout << s1.length()+s2.length() << "\n";
            continue;
        }

        ll p = -1;

        for(ll i = 0; i < s2.length(); i++){
            if(s2[i] == '2'){
                if(p==-1) p = i;
                l.push_back(i-p);
                // cout << i-p << " ";
            }
        } // cout << "\n";

        for(ll i = 0; i < s1.length(); i++){
            if(s1[i]=='2') continue;
            for(auto x: l){
                ll now = i+x;
                if(now >= s1.length()) break;
                if(s1[now]=='2'){
                    found = false;
                    break;
                }
            }
            if(found){
                if(i-p < 0) cout << s1.length()+abs(i-p) << "\n";
                else if(i+s2.length()-(p+1) >= s1.length()) cout << s1.length()+s2.length()-(s1.length()-(i-p)) << "\n";
                else cout << s1.length() << "\n";
                
                break;
            }
        }

        if(!found) cout << s1.length()+s2.length() << "\n";

    }

    return 0;
}