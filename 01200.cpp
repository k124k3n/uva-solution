#include <bits/stdc++.h>
using namespace std;

#define ll long long

unordered_set<char> op({
    '-', '+'
});

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    cin.ignore(1000, '\n');
    while(n--){
        string str; getline(cin, str);
        ll mark = 0, xl=0, xr=0, vl=0, vr=0;
        for(ll i = 0; str[i]; i++){
            if(str[i] == '-'){
                str.insert(i, " ");
                i++;
            }

            else if(str[i] == '+'){
                str[i] = ' ';
            }

            else if(str[i] == '=') mark = i;

            else if(str[i]=='x'){
                if(!str[i-1] || str[i-1] == ' ' || str[i-1] == '-' || str[i-1] == '=') str.insert(i, "1");
            }
        }

        string left = str.substr(0,mark);
        string right = str.substr(mark+1);

        stringstream ssl(left), ssr(right); string temp;
        // cout << right << "\n";
        // cout << left << "\n";
        while(ssl >> temp){ // left part
            // cout << *(temp.end()-1) << " ";
            if(*(temp.end()-1) == 'x'){ // extract x
                temp.pop_back();
                
                xl += stoi(temp);
                continue;
            }

            vl += stoi(temp);
        }

        while(ssr >> temp){ // right part
            // cout << *(temp.end()-1) << " ";
            if(*(temp.end()-1) == 'x'){ // extract x
                temp.pop_back();
                
                xr += stoi(temp);
                continue;
            }

            vr += stoi(temp);
        }

        ll x = xl-xr;
        ll v = vr-vl;
        
        if(x==0){
            if(v==0) cout << "IDENTITY\n";
            else cout << "IMPOSSIBLE\n";
            continue;
        }

        double res = floor((double)v/x);
        if(res==-0) cout << 0 << "\n";
        else cout << res << "\n";

        
    }
    return 0;
}