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
    string str; getline(cin, str);
    unordered_map<string, string> item_t;
    unordered_map<string, bool> isBlocked;
    unordered_map<string, string> prev;
    unordered_map<string, bool> isX;
    unordered_map<string, unordered_set<string>> hi;
    unordered_map<string, unordered_set<string>> uni;
    while(getline(cin, str)){
        if(str == "#") continue;
        if(str.empty()){
            item_t.clear();
            isBlocked.clear();
            prev.clear();
            hi.clear();
            uni.clear();
            cout << "\n";
            continue;
        }

        vector<string> r;
        stringstream ss(str); string temp;

        while(ss >> temp){
            r.push_back(temp);
        }

        string mode = r[0];
        string trid = r[1];
        string item = r[2];

        if(isBlocked[trid]){
            cout << "IGNORED\n";
            continue;
        }

        // if(hi[item].find(trid) != hi[item].end() && hi[item].size()==1){
            
        // }

        if(mode == "X"){
            bool c1 = uni[item].find(trid) != uni[item].end() && uni[item].size()==1;
            bool c2 = uni[item].find(trid) == uni[item].end() && uni[item].size()==0;
            if(c1||c2){
                cout << "GRANTED\n";
                
            }

            else{
                cout << "DENIED\n";
                isBlocked[trid] = true;
                continue;
            }
            
            hi[item].insert(trid);
            uni[item].insert(trid);
            continue;
        }

        else{
            bool c1 = hi[item].find(trid) != hi[item].end() && hi[item].size()==1;
            bool c2 = hi[item].find(trid) == hi[item].end() && hi[item].size()==0;
            if(c1||c2){
                cout << "GRANTED\n";
            }
            
            else{
                cout << "DENIED\n";
                isBlocked[trid] = true;
                continue;
            }

            uni[item].insert(trid);
        }


    }

    return 0;
}

