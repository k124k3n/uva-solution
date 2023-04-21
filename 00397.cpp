#include <bits/stdc++.h>
using namespace std;

#define ll long long

unordered_set<char> op(
    {'+', '-', '=', '*', '/'}
);

unordered_set<string> opx(
    {"+", "-", "=", "*", "/"}
);

void print(vector<string> hi){
    for(ll i = 0; i < hi.size(); i++){
        cout << hi[i];

        if(i != hi.size()-1) cout << " ";
    }

    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;
    while(getline(cin, str)){
        if(str == "") continue;
        vector<string> hi;

        for(ll i = 0; str[i]; i++){
            if(op.find(str[i]) != op.end()){
                str.insert(i, " ");
                str.insert(i+2, " ");
                i++;
            }
        }

        stringstream ss(str);
        string temp;

        while(ss >> temp){
            // if(hi.size() >= 1 && *(hi.end()-1) == "-" && temp == "-"){
            //     hi.pop_back();
            //     hi.push_back("+");
            //     continue;
            // }

            if(hi.size() >= 2 && opx.find(*(hi.end()-1)) != opx.end() && opx.find(*(hi.end()-2)) != opx.end() && isdigit(temp[0])){
                string hm = *(hi.end()-1);
                hi.pop_back();
                hi.push_back(to_string(stoi(hm+temp)));
                continue;
            }

            // if(hi.size() >= 2 && *(hi.end()-1) == "+" && opx.find(*(hi.end()-2)) != opx.end() && isdigit(temp[0])){
            //     hi.pop_back();
            //     hi.push_back("+"+temp);
            //     continue;
            // }

            hi.push_back(temp);
        }

        if(hi.size()==0)continue;

        // cout << str << "\n";

        print(hi);

        while(hi.size()>=3 && hi[1] != "="){
            ll plus = find(hi.begin(), hi.end(), "+") - hi.begin();
            ll minus = find(hi.begin(), hi.end(), "-") - hi.begin();
            ll times = find(hi.begin(), hi.end(), "*") - hi.begin();
            ll div = find(hi.begin(), hi.end(), "/") - hi.begin();

            if(times < div && times != hi.size()){
                ll res = stoi(hi[times-1]) * stoi(hi[times+1]);
                hi[times] = to_string(res);
                hi.erase(hi.begin()+times+1);
                hi.erase(hi.begin()+times-1);
            }

            else if(div != hi.size()){
                ll res = stoi(hi[div-1]) / stoi(hi[div+1]);
                hi[div] = to_string(res);
                hi.erase(hi.begin()+div+1);
                hi.erase(hi.begin()+div-1);
            }

            else if(plus < minus && plus != hi.size()){
                ll res = stoi(hi[plus-1]) + stoi(hi[plus+1]);
                hi[plus] = to_string(res);
                hi.erase(hi.begin()+plus+1);
                hi.erase(hi.begin()+plus-1);
            }

            else if(minus != hi.size()){
                ll res = stoi(hi[minus-1]) - stoi(hi[minus+1]);
                hi[minus] = to_string(res);
                hi.erase(hi.begin()+minus+1);
                hi.erase(hi.begin()+minus-1);
            }

            print(hi);
        }

        
        if(cin.good()) cout << "\n";

    }
    return 0;
}