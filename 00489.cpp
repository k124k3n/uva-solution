#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll round;
    while(cin >> round && round != -1){
        set<char> words;
        unordered_set<char> hm;
        map<char, bool> vis;
        string temp = "";
        bool win = false;
        ll wrong = 0;
        string a,b; cin >> a >> b;
        for(ll i = 0; i < a.length(); i++){
            words.insert(a[i]);
        }

        for(ll i = 0; i < b.length(); i++){
            if(!vis[b[i]]){
                temp += b[i];
                vis[b[i]] = true;
            }
        }

        for(ll i = 0; i < temp.length(); i++){
            if(wrong == 7) break;

            if(words.find(temp[i]) != words.end()){
                words.erase(temp[i]);
                if(words.size() == 0){
                    win = true;
                    break;
                }
            }

            else ++wrong;
        }

        cout << "Round " << round << "\n";
        if(win) cout << "You win.\n";
        else if(wrong >= 7) cout << "You lose.\n";
        else cout << "You chickened out.\n";

    }

    return 0;
}