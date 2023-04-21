#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t; cin >> t;

    while(t--){
        bool emp = true;
        string arr[3], cp[3];

        for(ll i = 0; i < 3; i++){    
            cin >> arr[i];
            cp[i] = arr[i];
            for(ll j = 0; j < 3; j++) if(arr[i][j] == '1') emp = false;
            
        }


        if(emp) cout << -1 << "\n";
        else{
            ll cnt = 0;
            while(!emp){
                emp = true;
                for(ll i = 0; i < 3; i++){
                    for(ll j = 0; j < 3; j++){
                        ll sum = 0;
                        sum += j>0 && (arr[i][j-1] - '0');
                        sum += i>0 && (arr[i-1][j] - '0');
                        sum += j<2 && (arr[i][j+1] - '0');
                        sum += i<2 && (arr[i+1][j] - '0');
                        
                        
                        sum %= 2;

                        cp[i][j] = '0' + sum;
                        if(sum==1) emp = false;
                    }
                }

                if(!emp) ++cnt;

                for(ll i = 0; i < 3; i++){
                    arr[i] = cp[i]; // sebagai [rev]
                } 
            }

            cout << cnt << "\n";

        }


    }
    
    return 0;
}