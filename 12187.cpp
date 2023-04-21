#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n,r,c,k;

    while(cin >> n >> r >> c >> k && n){
        ll arr[r][c], cp[r][c];

        for(ll i = 0; i < r; i++){
            for(ll j = 0; j < c; j++){
                cin >> arr[i][j];
                cp[i][j] = arr[i][j];
            }
        }


        for(ll p = 0; p < k; p++){
            for(ll i = 0; i < r; i++){
                for(ll j = 0; j < c; j++){
                    if(i>0 && (arr[i-1][j]+1)%n == arr[i][j]) cp[i][j] = arr[i-1][j];
                    if(j>0 && (arr[i][j-1]+1)%n == arr[i][j]) cp[i][j] = arr[i][j-1];
                    if(i<(r-1) && (arr[i+1][j]+1)%n == arr[i][j]) cp[i][j] = arr[i+1][j];
                    if(j<(c-1) && (arr[i][j+1]+1)%n == arr[i][j]) cp[i][j] = arr[i][j+1];
                }
            }

            for(ll i = 0; i < r; i++){
                for(ll j = 0; j < c; j++){
                    arr[i][j] = cp[i][j];
                }
            }
        }

        for(ll i = 0; i < r; i++){
            for(ll j = 0; j < c; j++){
                cout << cp[i][j];
                if(j!=(c-1)) cout << " ";
            }

            cout << "\n";
        }
    }
    return 0;
}