#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n; string num;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    
    while(cin >> n >> num && n){
        char hi[20][n+20][n*2+9];
        for(ll k = 0; k <= 9; k++){
            for(ll i = 0; i < n*2+9; i++){ // fill initial
                for(ll j = 0; j < n+20; j++){
                    hi[k][i][j] = ' ';
                }
            }
        }
        // =====================================
        

        for(ll i = 1; i < n*2+3; i++){ // FILL ONE
            ll sum = 0;
            while(sum < n){
                hi[1][i][n+1] = '|'; // FILL VERRIGHT
                ++i;
                ++sum;
            }
        }
        // =====================================
        
        for(ll i = 0; i < n*2+3; i++){ // fill two
            
            for(ll j = 1; j < n+1; j++){
                hi[2][i][j] = '-'; // FILL HOR
            } ++i;

            ll sum = 0;
            while(sum < n){
                hi[2][i][n+1] = '|'; // FILL VERRIGHT
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[2][i][j] = '-'; // FILL HOR
            } ++i;

            sum = 0;
            while(sum < n){
                hi[2][i][0] = '|'; // FILL VERLEFT
                ++i;
                ++sum;
            } 

            for(ll j = 1; j < n+1; j++){
                hi[2][i][j] = '-'; // FILL HOR
            } ++i;


        }
        // =====================================
        for(ll i = 0; i < n*2+3; i++){ // fill three
            
            for(ll j = 1; j < n+1; j++){
                hi[3][i][j] = '-'; // FILL HOR
            } ++i;

            ll sum = 0;
            while(sum < n){
                hi[3][i][n+1] = '|'; // FILL VERRIGHT
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[3][i][j] = '-'; // FILL HOR
            } ++i;

            sum = 0;
            while(sum < n){
                hi[3][i][n+1] = '|'; // FILL VERRIGHT
                ++i;
                ++sum;
            } 

            for(ll j = 1; j < n+1; j++){
                hi[3][i][j] = '-'; // FILL HOR
            } ++i;

        }
        // =====================================
        for(ll i = 1; i < n*2+3; i++){ // fill four
            
            ll sum = 0;
            while(sum < n){
                hi[4][i][n+1] = '|'; // FILL VERLEFTRIGHT
                hi[4][i][0] = '|';
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[4][i][j] = '-'; // FILL HOR
            } ++i;

            sum = 0;
            while(sum < n){
                hi[4][i][n+1] = '|'; // FILL VERRIGHT
                ++i;
                ++sum;
            } 

        }
        // =====================================
        for(ll i = 0; i < n*2+3; i++){ // fill five

            for(ll j = 1; j < n+1; j++){
                hi[5][i][j] = '-'; // FILL HOR
            } ++i;

            ll sum = 0;
            while(sum < n){
                hi[5][i][0] = '|'; // FILL VERLEFT
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[5][i][j] = '-'; // FILL HOR
            } ++i;

            sum = 0;
            while(sum < n){
                hi[5][i][n+1] = '|'; // FILL VERRIGHT
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[5][i][j] = '-'; // FILL HOR
            } ++i;
        }
        // =====================================
        for(ll i = 0; i < n*2+3; i++){ // fill six

            for(ll j = 1; j < n+1; j++){
                hi[6][i][j] = '-'; // FILL HOR
            } ++i;

            ll sum = 0;
            while(sum < n){
                hi[6][i][0] = '|'; // FILL VERLEFT
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[6][i][j] = '-'; // FILL HOR
            } ++i;

            sum = 0;
            while(sum < n){
                hi[6][i][n+1] = '|'; // FILL VERLEFTRIGHT
                hi[6][i][0] = '|';
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[6][i][j] = '-'; // FILL HOR
            } ++i;
        }
        // =====================================
        for(ll i = 0; i < n*2+3; i++){ // fill seven

            for(ll j = 1; j < n+1; j++){
                hi[7][i][j] = '-'; // FILL HOR
            } ++i;

            ll sum = 0;
            while(sum < n){
                hi[7][i][n+1] = '|'; // FILL VERRIGHT
                ++i;
                ++sum;
            } ++i;

            sum = 0;
            while(sum < n){
                hi[7][i][n+1] = '|'; // FILL VERRIGHT
                
                ++i;
                ++sum;
            }

        }
        // =====================================
        for(ll i = 0; i < n*2+3; i++){ // fill eight

            for(ll j = 1; j < n+1; j++){
                hi[8][i][j] = '-'; // FILL HOR
            } ++i;

            ll sum = 0;
            while(sum < n){
                hi[8][i][n+1] = '|'; // FILL VERLEFTRIGHT
                hi[8][i][0] = '|';
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[8][i][j] = '-'; // FILL HOR
            } ++i;

            sum = 0;
            while(sum < n){
                hi[8][i][n+1] = '|'; // FILL VERLEFTRIGHT
                hi[8][i][0] = '|';
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[8][i][j] = '-'; // FILL HOR
            } ++i;
        }
        // =====================================
        for(ll i = 0; i < n*2+3; i++){ // fill nine

            for(ll j = 1; j < n+1; j++){
                hi[9][i][j] = '-'; // FILL HOR
            } ++i;

            ll sum = 0;
            while(sum < n){
                hi[9][i][n+1] = '|'; // FILL VERLEFTRIGHT
                hi[9][i][0] = '|';
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[9][i][j] = '-'; // FILL HOR
            } ++i;

            sum = 0;
            while(sum < n){
                hi[9][i][n+1] = '|'; // FILL VERRIGHT
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[9][i][j] = '-'; // FILL HOR
            } ++i;
        }
        // =====================================
        for(ll i = 0; i < n*2+3; i++){ // fill zero

            for(ll j = 1; j < n+1; j++){
                hi[0][i][j] = '-'; // FILL HOR
            } ++i;

            ll sum = 0;
            while(sum < n){
                hi[0][i][n+1] = '|'; // FILL VERLEFTRIGHT
                hi[0][i][0] = '|';
                ++i;
                ++sum;
            }

            ++i;

            sum = 0;
            while(sum < n){
                hi[0][i][n+1] = '|'; // FILL VERLEFTRIGHT
                hi[0][i][0] = '|';
                ++i;
                ++sum;
            }

            for(ll j = 1; j < n+1; j++){
                hi[0][i][j] = '-'; // FILL HOR
            } ++i;
        }
        // =====================================
        
        for(ll i = 0; i < n*2+3; i++){ // final print
            for(ll j = 0; j < num.length(); j++){
                for(ll k = 0; k < n+2; k++){
                    // cout << num[j] - '0' << " " << i << " " << k << "= ";
                    cout << hi[num[j] - '0'][i][k];
                }
                if(j != num.length()-1)cout << " ";
            }
            cout<<"\n";
            if(i ==n*2+2)cout<<"\n";
        }
    }
    return 0;
}