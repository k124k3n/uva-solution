#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll Max = LLONG_MIN, Min = LLONG_MAX; // reseted
ll C = 0, K = 0; // reseted
double bigTreshold = 2.22, smallTreshold = 1.8; // dont need to reset
// bigTres = 2.212

map<string, string> decode; // dont need to reset
string bar; // dont need to reset
vector<string> final; // reseted

ll checkW(char c){
    if(isdigit(c)) return (c - '0');
    else return 10;
}

bool checkC(char c){
    C = 0;

    ll realLength = bar.length() - 2;
    for(ll i = 1; i <= realLength; i++){
        C += ( ( (realLength-i) % 10 ) + 1 ) * checkW(bar[i-1]);
    
        // cout << "Ccheck += " << ( ( (bar.length()-i) % 10 ) + 1 ) << " * " <<  checkW(bar[i-1]) << "\n";
    }

    // cout << "Ccheck = " << C << "\n";
    return (C%11 == checkW(c));

}

bool checkK(char c){
    K = 0;

    ll realLength = bar.length() - 2;

    for(ll i = 1; i <= realLength; i++){
        K += ( ( (realLength-i+1) % 9 ) + 1 ) * checkW(bar[i-1]);
    }

    K += C;

    // cout << "Kcheck = " << K << "\n";
    return (K%11 == checkW(c));
}

ll scan(ll l, ll r, vector<ll> raw){
    bar = "";
    string temp;
    ll stcnt = 0; // count how start we have

    for(ll i = l; i < r; i++){
        
        bool validNarrow =  (double) raw[i] <= (double) ((Min*105/95));
        bool validWide = (double) raw[i] >= (double) (Max*195/205);

        if(validNarrow){
            temp += "0";
        }

        else if(validWide){
            temp += "1";
        }

        else{
            final.push_back(bar);
            // cout << raw[i];
            // cout << " Unknown encoding!\n";
            return -1;
        }

        if(temp.length()==5){
            if(decode.find(temp) == decode.end()) return -1;
            if(decode[temp] == "S") ++stcnt;
            bar += decode[temp];
            temp = "";

            if(i < r-5){
                // validNarrow = (double) raw[i+1]/Min <= 1.16;
                validNarrow =  (double) raw[i+1] <= (double) ((Min*105/95));
                if(!validNarrow){
                    final.push_back(bar);
                    // cout << raw[i+1] << " " << Min << "\n";
                    // cout << "Narrow invalid!\n";
                    return -1;
                }
                i++;
            }
        }
    }

    
    if(bar[0] != 'S' || bar[bar.length()-1] != 'S' || stcnt != 2){
        final.push_back(bar);
        return -1;
    }
    bar.erase(0, 1); bar.pop_back();
    final.push_back(bar);
    // cout << bar << "\n";
    // cout << "C = " << bar[bar.length()-2] << "\n";
    // cout << "K = " << bar[bar.length()-1] << "\n";
    if(! checkC(bar[bar.length()-2])) return 0;
    if(! checkK(bar[bar.length()-1])) return 1;

    
    return 2;

}

/*
0 00001
1 10001
2 01001
3 11000
4 00101
5 10100
6 01100
7 00011
8 10010
9 10000
- 00100
*/

/*
BAD CODE CONDITION:
- There's no start, end, or 'S' count != 2
- Max/Min < smallTres || Max/Min > bigTres , there's only 1 kind of character

*/


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    decode["00001"] = "0"; decode["10001"] = "1"; decode["01001"] = "2"; decode["11000"] = "3";
    decode["00101"] = "4"; decode["10100"] = "5";  decode["01100"] = "6"; decode["00011"] = "7"; 
    decode["10010"] = "8"; decode["10000"] = "9"; decode["00100"] = "-"; decode["00110"] = "S";
    ll n; ll cs = 1;
    while(cin >> n && n){
        final.clear();
        vector<ll> raw; Max = LLONG_MIN, Min = LLONG_MAX;

        cout << "Case " << cs++ << ": ";
        for(ll i = 0; i < n; i++){
            ll bar; cin >> bar;
            raw.push_back(bar);
            Max = max(Max, bar);
            Min = min(Min, bar);
        }

        
        // cout << Max << " " << Tr << " " << Min << "\n";
        if(n < 29 || (n+1)%6 != 0){
            cout << "bad code\n";
            continue;
        }

        ll res1 = scan(0, n, raw);
        reverse(raw.begin(), raw.end());
        ll res2 = scan(0, n, raw);

        if(res1==2||res2==2){
            if(res1==2){
                final[0].pop_back();
                final[0].pop_back();
                cout << final[0] << "\n";
            }

            else{
                final[1].pop_back();
                final[1].pop_back();
                cout << final[1] << "\n";
            }
        }

    
        else if(res1==0||res2==0){
            cout << "bad C\n";
        }

        else if(res1==1||res2==1){
            cout << "bad K\n";
        }

        else cout << "bad code\n";
        
    }

    return 0;
}