#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll sum[10000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    string str;
    while(getline(cin, str)){
        stringstream ss(str);
        string temp;
        bool found = true;
        
        stack<ll> hi;
        while(ss >> temp){
            ll a = stoi(temp);

            if(a < 0){
                hi.push(a);
            }

            else{
                if(hi.empty() || hi.top() != (0-a)){
                    found = false;
                    for(ll i = 1; i <= hi.size()+1; i++){
                        sum[i] = 0;
                    }
                    break;
                }

                if(sum[hi.size()] >= a){
                    found = false;
                    for(ll i = 1; i <= hi.size(); i++){
                        sum[i] = 0;
                    }
                    hi.pop();
                    break;
                }

                sum[hi.size()-1] += a;
                sum[hi.size()] = 0;
                // cout << "sum[" << hi.size()-1 << "] = " << sum[hi.size()-1] << "\n";
                hi.pop();
            }
        }

        if(found && hi.empty()) cout << ":-) Matrioshka!\n";
        else cout << ":-( Try again.\n";
    }
    return 0;
}