#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    cin.ignore(1000, '\n');
    while(t--){
        string n,o;
        getline(cin, o); getline(cin, n);
        o = o.substr(1, o.length()-1);
        n = n.substr(1, n.length()-1);

        string temp; string num;
        bool onNumber = false;
        unordered_map<string, string> oldD, newD;
        for(ll i = 0; o[i]; i++){
            if(o[i]==':') onNumber = true;
            else if(o[i]==',' || o[i]=='}'){
                if(temp.empty()) continue;
                oldD[temp] = num;
                // cout << temp << " " << num << "\n";
                temp = "";
                num = "";
                onNumber = false;
            }

            else if(onNumber) num += string(1, o[i]);
            else temp += string(1, o[i]);
        }

        set<string> plus, minus, star;
        onNumber=false;

        for(ll i = 0; n[i]; i++){
            if(n[i]==':') onNumber = true;
            else if(n[i]==',' || n[i]=='}'){ //processed
                if(temp.empty()) continue;
                newD[temp] = num;

                // cout << temp << " " << num << "\n";
                if(oldD.find(temp) == oldD.end()) plus.insert(temp);
                else if(oldD[temp] != newD[temp]) star.insert(temp);
                temp = "";
                num = "";
                onNumber = false;
            }

            else if(onNumber) num += string(1, n[i]);
            else temp += string(1, n[i]);
        }

        for(auto x: oldD){
            if(newD.find(x.first)==newD.end()){
                minus.insert(x.first);
            }
        }

        ll i = 0;

        if(plus.size()==0&&minus.size()==0&&star.size()==0){
            cout << "No changes\n\n";
            continue;
        }

        if(plus.size()){
            cout << "+";
            for(auto x: plus){
                cout << x;
                if(i!=(plus.size()-1)) cout << ",";
                i++;
            } cout << "\n";
        }

        if(minus.size()){
            cout << "-";
            i = 0;
            for(auto x: minus){
                cout << x;
                if(i!=(minus.size()-1)) cout << ",";
                i++;
            } cout << "\n";

            
        }

        if(star.size()){
            cout << "*";
            i = 0;
            for(auto x: star){
                cout << x;
                if(i!=(star.size()-1)) cout << ",";
                i++;
            } cout << "\n";
        }
        
        cout << "\n";
    }
    return 0;
}