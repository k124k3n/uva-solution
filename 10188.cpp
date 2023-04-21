#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll n,m; ll cs = 0;
    while(cin >> n && n){
        cout << "Run #" << ++cs << ": ";
        string s[n], sn, tn; bool PE = false; bool WA = false;
        cin.ignore(1000, '\n');

        for(ll i = 0; i < n; i++){
            getline(cin, s[i]);
            
            for(auto x: s[i]){
                if(isdigit(x)) sn += string(1,x);
            }

            
        }

        // cin.ignore(1000, '\n');

        cin >> m;

        cin.ignore(1000, '\n');

        for(ll i = 0; i < m; i++){
            string temp; getline(cin, temp);
            

            for(auto x: temp){
                if(isdigit(x)) tn += string(1,x);
            }

            if(temp == s[i]) continue;
            else WA = true;
                
            
        }

        if(!WA && n==m) cout << "Accepted\n";
        else if(sn==tn) cout << "Presentation Error\n";
        else cout << "Wrong Answer\n";
        
    }
    return 0;
}