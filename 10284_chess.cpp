#include <bits/stdc++.h>
using namespace std;

#define ll long long

char board[9][9];
bool taken[9][9], vis[9][9];

ll sum;

void lowPawn(ll a, ll b){

    if(a+1 < 8 && b+1 < 8 && !vis[a+1][b+1]){
        --sum;
        // cout << a+1 << " " << b+1 << " taken!\n"; // debug
        vis[a+1][b+1] = true;
    }

    if(a+1 < 8 && b-1 >= 0 && !vis[a+1][b-1]){
        --sum;
        // cout << a+1 << " " << b+1 << " taken!\n"; // debug
        vis[a+1][b-1] = true;
    }
}

void pawn(ll a, ll b){
    
    if(a-1 >= 0 && b-1 >= 0 && !vis[a-1][b-1]){
        --sum;
        // cout << i << " " << j << " taken!\n"; // debug
        vis[a-1][b-1] = true;
    }

    if(a-1 >= 0 && b+1 < 8 && !vis[a-1][b+1]){
        --sum;
        // cout << i << " " << j << " taken!\n"; // debug
        vis[a-1][b+1] = true;
    }
    // if(a == 6 && !vis[4][b]){
    //     --sum;
    //     //cout << 4 << " " << b << " taken!\n"; // debug
    //     vis[4][b] = true;
    // }
}

void diag(ll a, ll b){
    for(ll i = a+1, j = b+1; i < 8 && j < 8 && !taken[i][j]; i++, j++){ // check tenggara
        if(!vis[i][j]){
            --sum;
            vis[i][j] = true;
        }
    }

    for(ll i = a-1, j = b+1; i >= 0 && j < 8 && !taken[i][j]; i--, j++){ // check timur laut
        if(!vis[i][j]){
            --sum;
            vis[i][j] = true;
        }
    }

    for(ll i = a-1, j = b-1; i >= 0 && j >= 0 && !taken[i][j]; i--, j--){ // check barat laut
        if(!vis[i][j]){
            --sum;
            vis[i][j] = true;
        }
    }

    for(ll i = a+1, j = b-1; i < 8 && j >= 0 && !taken[i][j]; i++, j--){ // check barat daya
        if(!vis[i][j]){
            --sum;
            vis[i][j] = true;
        }
    }
}

void slope(ll a, ll b){
    for(ll i = a-1, j = b; i >= 0 && !taken[i][j]; i--){ // atas
        if(!vis[i][j]){
            --sum;
            vis[i][j] = true;
        }
    }

    for(ll i = a+1, j = b; i < 8 && !taken[i][j]; i++){ // bawah
        if(!vis[i][j]){
            --sum;
            vis[i][j] = true;
        }
    }

    for(ll i = a, j = b-1; j >= 0 && !taken[i][j]; j--){ // kiri
        if(!vis[i][j]){
            --sum;
            vis[i][j] = true;
        }
    }

    for(ll i = a, j = b+1; j < 8 && !taken[i][j]; j++){ // kanan
        if(!vis[i][j]){
            --sum;
            vis[i][j] = true;
        }
    }
}

void king(ll a, ll b){
    ll e[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    ll f[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(ll i = 0; i < 8; i++){
        ll imove = a + e[i];
        ll jmove = b + f[i];
        bool hi = imove >= 0 && imove < 8;
        bool hi1 = jmove >= 0 && jmove < 8;
        if(hi && hi1 && !vis[imove][jmove]){
            --sum;
            vis[imove][jmove] = true;
        }
    }
}

void knight(ll a, ll b){
    ll e[8] = {-2, -2, 2, 2, 1, 1, -1, -1};
    ll f[8] = {-1, 1, -1, 1, 2, -2, 2, -2};

    for(ll i = 0; i < 8; i++){
        ll imove = a + e[i];
        ll jmove = b + f[i];
        bool hi = imove >= 0 && imove < 8;
        bool hi1 = jmove >= 0 && jmove < 8;
        if(hi && hi1 && !vis[imove][jmove]){
            --sum;
            vis[imove][jmove] = true;
            // knight(imove, jmove);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    while(cin >> str){
        sum = 64;
        for(ll i = 0; i < 9; i++)
            for(ll j = 0; j < 9; j++){
               board[i][j] = '0';
               taken[i][j] = false;
               vis[i][j] = false;
            }
    
        ll i = 0, j = 0;

        for(ll g = 0; g < str.length(); g++){ // filling board
            if(isdigit(str[g])){
                j += str[g] - '0';
                continue;
            }

            else if(str[g] == '/'){
                ++i; j = 0;
                continue;
            }

            else{
                taken[i][j] = true;
                board[i][j] = str[g];
                vis[i][j] = true;
                --sum;
            }
            j++;
        }

        // cout << sum << " = sum awal\n";
        // for(ll i = 0; i < 8; i++){ // debug
        //     for(ll j = 0; j < 8; j++) cout << board[i][j];
        //     cout << "\n";
        // }

        for(i = 0; i < 8; i++){
            for(j = 0; j < 8; j++){
                if(board[i][j] == '0') continue;
                if(board[i][j] == 'p'){
                    // cout << i << " " << j << " adalah pawn hitam\n"; // debug
                    lowPawn(i,j);
                    continue;
                }
                else board[i][j] = toupper(board[i][j]);
                if(board[i][j] == 'N'){
                    knight(i, j);
                }
                else if(board[i][j] == 'K') king(i, j);
                else if(board[i][j] == 'B') diag(i, j);
                else if(board[i][j] == 'R')slope(i, j);
                else if(board[i][j] == 'P'){
                    // cout << i << " " << j << " adalah pawn putih\n"; // debug
                   pawn(i, j);
                    
                }
                else if(board[i][j] == 'Q'){
                    slope(i, j), diag(i,j);
                }
            }
        }


        cout << sum << "\n";

    }


    return 0;
}