#include <bits/stdc++.h>
using namespace std;

#define ll long long

set<char> nk({
    'a', 'i', 'u', 'e', 'o'
});

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;

    // for(auto x: nk){
    //     cout << x << " "; 

    // } cout << "\n";
    while(getline(cin, str)){
        string hi = str;
        for(ll i = 0; hi[i]; i++){
            if(!isalpha(hi[i])) hi[i] = ' ';
        }


        stringstream ss(hi);
        string temp;
        queue<string> q;

        while(ss >> temp){
            if(nk.find(tolower(temp[0])) == nk.end()){
                temp = temp.substr(1) + string(1, temp[0]) + "ay";
                q.push(temp);
            }

            else{
                temp += "ay";
                q.push(temp);
            }
        }

        for(ll i = 0; str[i]; i++){
            if(isalpha(str[i])){
                cout << q.front();
                q.pop();
                while(isalpha(str[i]) && str[i]) ++i;
                --i;
                continue;
            }

            cout << str[i];

        }

        cout << "\n";

    }
    return 0;
}