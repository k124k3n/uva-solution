#include <bits/stdc++.h>
using namespace std;

#define ll long long

queue<char> lc, rc; // content


string same[7] = {
    "........||........",
    ".../\\...||.../\\...",
    "../..\\..||../..\\..",
    "./....\\.||./....\\.",
    "/......\\||/......\\",
    "\\______/||\\______/",
    "........||........",
};

string big[7] = {
    ".../\\...||........",
    "../..\\..||........",
    "./....\\.||.../\\...",
    "/......\\||../..\\..",
    "\\______/||./....\\.",
    "........||/......\\",
    "........||\\______/",
};

string small[7] = {
    "........||.../\\...",
    "........||../..\\..",
    ".../\\...||./....\\.",
    "../..\\..||/......\\",
    "./....\\.||\\______/",
    "/......\\||........",
    "\\______/||........",
};

void print(string core[7]){
    for(ll i = 0; i < 7; i++){ 
        ll j = 0; // left words
        for(; j < 9 && core[i][j] != '/'; j++){
            cout << core[i][j];
        } if(j < 9 && core[i][j] == '/') cout << core[i][j];
        
        ll k = j+1;

        for(; k < 9 && core[i][k] != '\\'; k++){ // print isi kiri
            if(!lc.empty()){
                cout << lc.front();
                lc.pop();
            }

            else cout << core[i][k];
        }

        while(k < 9){
            cout << core[i][k];
            ++k;
        }

        j = 9;

        for(; j < 18 && core[i][j] != '/'; j++){
            cout << core[i][j];
        } if(j < 18 && core[i][j] == '/') cout << core[i][j];

        k = j+1;

        for(; k < 18 && core[i][k] != '\\'; k++){ // print isi kanan
            if(!rc.empty()){
                cout << rc.front();
                rc.pop();
            }

            else cout << core[i][k];
        }

        while(k < 18){
            cout << core[i][k];
            ++k;
        }

        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    ll cs = 0;
    while(t--){
        lc = {}; rc = {};
        string core[7];
        cout << "Case " << ++cs << ":\n";
        string arr[8];

        ll lp = 0, rp = 0, lw = 0, rw = 0;
        

        for(ll i = 0; i < 8; i++){
            cin >> arr[i];
        }

        for(ll i = 0; i < 7; i++){ // left
            bool found = false;
            for(ll j = 0; j < 8; j++){
                if(arr[i][j] == '/'){
                    lp = i;
                    found = true;
                    break;
                }

                if(found) break;
            }
        }

        for(ll i = 0; i < 7; i++){ // right
            bool found = false;
            for(ll j = 10; j < 18; j++){
                if(arr[i][j] == '/'){
                    rp = i;
                    found = true;
                    break;
                }

                if(found) break;
            }
        }

        for(ll i = 0; i < 7; i++){ // left words
            ll j = 0;
            for(; j < 8 && arr[i][j] != '/'; j++);
            

            for(ll k = j+1; k < 8 && arr[i][k] != '\\'; k++){
                lc.push(arr[i][k]);
                if(!isalpha(arr[i][k])) continue;

                ll word = arr[i][k];
                bitset<32> hi(word);

                ll sz = log2(word)+1 - hi.count();
                lw += 500*hi.count() + 250*sz;

            }

        }

        for(ll i = 0; i < 7; i++){ // right words
            ll j = 10;

            for(; j < 18 && arr[i][j] != '/'; j++);
            

            for(ll k = j+1; k < 18 && arr[i][k] != '\\'; k++){
                rc.push(arr[i][k]);
                if(!isalpha(arr[i][k])) continue;

                ll word = arr[i][k];
                bitset<32> hi(word);

                ll sz = log2(word)+1 - hi.count();
                rw += 500*hi.count() + 250*sz;

            }

        }

        bool c1 = ((lp < rp) == (lw < rw)) && ((lp < rp) && (lw < rw));
        bool c2 = ((lp == rp) == (lw == rw)) && ((lp == rp) && (lw == rw));
        bool c3 = ((lp > rp) == (lw > rw)) && ((lp > rp) && (lw > rw));

        if(c1||c2||c3) cout << "The figure is correct.\n";
        else{
            if(lw<rw) print(big);
            else if(lw>rw) print(small);
            else print(same);
        }
    }

    return 0;
}