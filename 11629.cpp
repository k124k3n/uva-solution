#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll p,g; cin >> p >> g;

    unordered_map<string, ll> el;
    for(ll i = 0; i < p; i++){
        string pr; double vote; cin >> pr >> vote;
        vote *= 1000;

        
        el[pr] = vote;
    }

    cin.ignore(100, '\n');

    for(ll i = 0; i < g; i++){
        
        string str; getline(cin, str);

        // cout << str << "\n";
        stringstream ss(str); string temp;

        ll sum = 0;

        bool found = false;
        bool iseq = false;
        string eq; ll res = 0;
        while(ss >> temp){

            // cout << temp << "\n";
            if(temp=="+") continue;

            else if(temp == "<" || temp == ">" || temp == ">=" || temp == "<=" || temp == "="){
                iseq = true;
                eq = temp;
            }
                
            else if(iseq){
                res = stoi(temp)*1000;
            }

            else sum += el[temp];
        }

        if(eq=="<") found = (sum < res);
        else if(eq==">") found = (sum > res);
        else if(eq=="=") found = (sum == res);
        else if(eq=="<=") found = (sum <= res);
        else if(eq==">=") found = (sum >= res);

        // cout << sum << " " << res << "\n";
        cout << "Guess #" << i+1 << " was ";
        if(found) cout << "correct.\n";
        else cout << "incorrect.\n";
    }
    return 0;
}