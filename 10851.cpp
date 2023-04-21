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
        string arr[10];

        for(ll i = 0; i < 10; i++) cin >> arr[i];

        for(ll j = 1; j < arr[0].length()-1; j++){
            string temp;
            for(ll i = 1; i <= 8; i++){
                if(arr[i][j] == '/') temp += "0";
                else temp += "1";
            }

            reverse(temp.begin(), temp.end());

            cout << (char) stoi(temp, NULL, 2);
        }

        cout << "\n";
    }
    return 0;
}