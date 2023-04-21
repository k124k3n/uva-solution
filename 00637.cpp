#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    while(cin >> n && n){
        
        ll sz = ceil((double)n/4);
        ll arr[sz*2][2]; ll dr[2] = {1, 0};

        for(ll i = 0; i < sz*2; i++){ // initialization
            for(ll j = 0; j < 2; j++) arr[i][j] = 0;
        }

        ll cnt = 1;

        for(ll i = 0; i < sz*2 && cnt <= n; i++){ // fill up-down
            arr[i][dr[i%2]] = cnt;
            ++cnt;
        }

        for(ll i = sz*2-1; i >= 0 && cnt <= n; i--){
            
            arr[i][dr[(i+1)%2]] = cnt;
            ++cnt;
        }

        cout << "Printing order for " << n << " pages:\n";
        string order[2] = {"front", "back "};

        for(ll i = 0; i < sz*2; i++){
            if(arr[i][0] == 0 && arr[i][1]==0) continue;
            cout << "Sheet " << (i/2)+1 << ", " << order[i%2] << ": ";
            for(ll j = 0; j < 2; j++){
                if(arr[i][j] == 0) cout << "Blank";
                else cout << arr[i][j];
                if(j != 1) cout << ", ";
                else cout << "\n";
            }
        }
    }

    return 0;
}