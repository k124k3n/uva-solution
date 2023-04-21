#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;

    while(cin >> str){
        
        vector<ll> pos;
        ll sum = 0;

        for(ll i = 0; i < str.length(); i++){
            if(str[i] == 'X'){
                if(pos.size() == 0){
                    sum = max(sum, i-1);
                }

                else{
                    ll res = i - *(pos.end()-1) - 1;
                    if(res%2==0) sum = max(sum, res/2-1);
                    else sum = max(sum, res/2);
                }

                pos.push_back(i);
            }
        }

        ll res = (str.length()-1) - *(pos.end()-1);
        sum = max(sum, res-1);
        cout << sum << "\n";

        
    }
    return 0;
}