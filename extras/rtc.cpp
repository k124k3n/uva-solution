#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("rtc.in", "r", stdin);
    freopen("rtc.out", "w", stdout);

    srand(time(NULL));
    ll n = 1 + (rand()%15);
    ll m = 1 + (rand()%100000);
    cout << n << " " << m << "\n";

    for(ll i = 0; i < m; i++){
        ll com = 1 + (rand()%3);
        if(com==1||com==2){
            ll a = 1 + (rand()%n);
            ll b = 1 + (rand()%n);
            cout << com << " " << a << " " << b << "\n";
        }

        else{
            ll a = 1 + (rand()%n);
            cout << com << " " << a << "\n";
        }
    }

    return 0;
}