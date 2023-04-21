#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;
    vector<string> sv;
    queue<string> q;
    while(getline(cin, str) && str != "0"){
        
        string temp = str, b;
        for(ll i = 0; temp[i]; i++){
            if(!isdigit(temp[i]) && !isalpha(temp[i])) temp[i] = ' ';
        }

        stringstream ss(temp);
        while(ss >> b){
            if(isdigit(b[0])){
                
                ll hi = stoi (b);
                string hm  = *(sv.end()-hi);
                q.push(hm);
                // cout << hm << "\n";
                sv.erase(sv.end()-hi);
                sv.push_back(hm);

                
            }

            else sv.push_back(b);
        }

        for(ll i = 0; str[i]; i++){
            if(isdigit(str[i])){
                cout << q.front();
                q.pop();
                while(str[i]&&isdigit(str[i])){
                    ++i;
                }
                --i;
                continue;
            }
            
            cout << str[i];

        }

        cout << "\n";
    }
    return 0;
}