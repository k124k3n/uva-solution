#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    double summel = 0;
    double summaw = 0;
    for(ll i = 0; i < n; i++){
        ll temp; cin >> temp;

        // cout << sqrt(temp) << "\n";
        if(i%2==0){ // melati
            double akar = sqrt(temp);
            summel += (double) akar;
        }

        else{
            double akar = sqrt(temp);
            summaw += (double) akar;
        }
    }

    cout << summel << "\n" << summaw << "\n";
    return 0;
}