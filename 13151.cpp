#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll check(char c){
    if(isalpha(c)) return (c - 'A' + 10);
    else return (c - '0');
}

ll simul(string ins, ll i){
    if(ins == "++i") return (i+1);
    if(ins == "--i") return (i-1);
    else return i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string init; ll n;
    while(cin >> init >> n && n){
        ll multi = 1, real=0, grade = 0;
        
        if(init.length() > 1 && init[1] == 'x'){ // hexa
            for(ll i = init.length()-1; i > 1; i--){
                real += check(init[i]) * multi;
                

                multi *= 16;
            }
        }

        else if(init[0] == '0'){ // octal
            for(ll i = init.length()-1; i > 0; i--){
                real += check(init[i]) * multi;
                multi *= 8;
            }
        }
        else real = stoi(init);

        for(ll i = 0; i < n; i++){
            string ins; ll hope; cin >> ins >> hope;
            if(simul(ins, real) == hope) ++grade;
            if(ins=="i++") ++hope;
            else if(ins == "i--") --hope;
            real = hope;
        }
        cout << grade << "\n";
    }

    return 0;
}