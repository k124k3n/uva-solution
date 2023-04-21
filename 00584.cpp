#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll check(char hi, char k = ' '){
    if(hi == 'X') return 10;
    else if(hi == '/') return 10 - (k - '0');
    else return (hi - '0');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    while(getline(cin,str) && str != "Game Over"){
        ll score = 0; ll round = 1;
        vector<ll> real;

        for(ll i = 0; i < str.length(); i += 2){
            score += check(str[i], str[max((ll) 0, i-2)]);
            real.push_back(check(str[i], str[max((ll) 0, i-2)]));
            real.push_back(-1);
        }

        // cout << "Early score = " << score << "\n";

        for(ll i = 0; i < str.length(); i += 2){
            // cout << "Round " << round << ": ";
            if((str[i] == 'X') && (round < 10)){
                score += real[i+2] + real[i+4];
                // cout << "Score += " << real[i+2] << " + " << real[i+4] << "\n";
                ++round;
            }

            else if(str[i+2] == '/' && round < 10){
                score += real[i+4];
                // cout << "Score += " << real[i+4] << "\n";
                i += 2;
                ++round;
            }

            else{
                // cout << "\n";
                i += 2;
                ++round;
            }
        }

        cout << score << "\n";

    }

    return 0;
}

/*
1 0 1 / 2 2 X 3 3 X 1 / 3 / X 1 2
Game Over
*/