#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool O_win = false, X_win = false;
string ttt[3];

void check(){
    ll Os=0, Xs=0;
    for(ll i = 0, j = 0; i < 3 && j < 3; i++, j++){ // check diagonal kiri
        if(ttt[i][j] == 'O') ++Os;
        else if(ttt[i][j] == 'X') ++Xs;
    }

    if(Xs == 3) X_win = true;
    if(Os == 3) O_win = true;
    Xs = 0, Os = 0;
    // =====================================================================
    for(ll i = 0, j = 2; i < 3 && j >= 0; i++, j--){ // check diagonal kanan
        if(ttt[i][j] == 'O') ++Os;
        else if(ttt[i][j] == 'X') ++Xs;
    }

    if(Xs == 3) X_win = true;
    if(Os == 3) O_win = true;
    Xs = 0, Os = 0;
    // =====================================================================
    for(ll i = 0, j = 0; i < 3; i++){ // check UpDown Kiri
        if(ttt[i][j] == 'O') ++Os;
        else if(ttt[i][j] == 'X') ++Xs;
    }

    if(Xs == 3) X_win = true;
    if(Os == 3) O_win = true;
    Xs = 0, Os = 0;
    // =====================================================================
    for(ll i = 0, j = 1; i < 3; i++){ // check UpDown Tengah
        if(ttt[i][j] == 'O') ++Os;
        else if(ttt[i][j] == 'X') ++Xs;
    }

    if(Xs == 3) X_win = true;
    if(Os == 3) O_win = true;
    Xs = 0, Os = 0;
    // =====================================================================
    for(ll i = 0, j = 2; i < 3; i++){ // check UpDown Kanan
        if(ttt[i][j] == 'O') ++Os;
        else if(ttt[i][j] == 'X') ++Xs;
    }

    if(Xs == 3) X_win = true;
    if(Os == 3) O_win = true;
    Xs = 0, Os = 0;
    // =====================================================================
    for(ll i = 0, j = 0; j < 3; j++){ // check LeftRight Atas
        if(ttt[i][j] == 'O') ++Os;
        else if(ttt[i][j] == 'X') ++Xs;
    }

    if(Xs == 3) X_win = true;
    if(Os == 3) O_win = true;
    Xs = 0, Os = 0;
    // =====================================================================
    for(ll i = 1, j = 0; j < 3; j++){ // check LeftRight Tengah
        if(ttt[i][j] == 'O') ++Os;
        else if(ttt[i][j] == 'X') ++Xs;
    }

    if(Xs == 3) X_win = true;
    if(Os == 3) O_win = true;
    Xs = 0, Os = 0;
    // =====================================================================
    for(ll i = 2, j = 0; j < 3; j++){ // check LeftRight Bawah
        if(ttt[i][j] == 'O') ++Os;
        else if(ttt[i][j] == 'X') ++Xs;
    }

    if(Xs == 3) X_win = true;
    if(Os == 3) O_win = true;
    Xs = 0, Os = 0;
    // =====================================================================


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        O_win = false, X_win = false;
        bool dot = false;
        for(ll i = 0; i < 3; i++) cin >> ttt[i];
        ll o = 0, x = 0;
        for(ll i = 0; i < 3; i++){
            for(ll j = 0; j < 3; j++){
                if(ttt[i][j] == 'O') ++o;
                else if(ttt[i][j] == 'X') ++x;
                else dot = true;
            }
        }

        if(abs(x - o) >= 2) cout << "no\n";
        else{
            check();
            bool seri = !O_win && !X_win;

            if(seri && dot){
                if(o > x) cout << "no\n";
                else cout << "yes\n";
            }
            else{
                bool c = O_win && x != o;

                bool d = x != (o+1) && (X_win || seri) && !(X_win && seri);

                if(X_win && O_win) cout << "no\n";
                else if(c || d) cout << "no\n";
                else cout << "yes\n";
            }
        }
    }   
    return 0;
}