#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a,b,c;

bool king_check(ll now){

    if(now/8 == c/8) {
        for(ll i = c+1; i % 8 != 0; i++){ // check timur
            if(now == i) return true;
        }
        for(ll i = c-1; i >= 0 && i % 8 != 7; i--){ // check barat
            if(now == i) return true;
        }
    }

    else if(abs(now-c) % 8 == 0){
        for(ll i = c-8; i >= 0; i -= 8){ // check utara
            if(now == i) return true;
        }

        for(ll i = c+8; i <= 63; i += 8){ // check selatan
            if(now == i) return true;
        }
    }

    return false;
}

bool encounter_check(){
    bool hi1 = (a/8) == (c/8) && (c/8) == (b/8) && a > min(b,c) && a < max(b,c);
    bool hi8 = abs(a-c) % 8 == 0 && abs(b-c) % 8 == 0 && abs(a-b) % 8 == 0 && a > min(b,c) && a < max(b,c);
    return (hi1||hi8);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> a >> b >> c){
        // cout << a - (a%8) << " " << a - (a%8) + 7 << "\n";
        bool not_legal = ((abs(b-c) % 8 != 0 && (c < (b - (b%8)) || c > (b - (b%8) + 7))) || a==c || b==c);
        
        bool ex = false;
        bool win = false;
        vector<ll> extra;
        if(a%8 != 0) extra.push_back(a-1); // check kiri
        if(a%8 != 7) extra.push_back(a+1); // check kanan
        if(a > 7) extra.push_back(a-8); // check atas
        if(a < 56) extra.push_back(a+8); // check bawah

        for(auto x: extra){
            if(c == x) ex = true;
            if(!king_check(x)) win = true;
            
        }


        if(a==b) cout << "Illegal state\n";
        
        else if((not_legal || encounter_check())) cout << "Illegal move\n";
        else if(ex && win) cout << "Move not allowed\n";
        else if(win) cout << "Continue\n";
        else cout << "Stop\n";
    }

    return 0;
}