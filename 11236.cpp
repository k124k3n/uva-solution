#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cout << fixed << setprecision(2);
    for(ll i = 1; i <= 1996; i++){
        for(ll j = i; (2000-i-j) > 0; j++){
            for(ll k = j; (2000-i-j-k) > k; k++){
                if(i*j*k<=1000000) continue;
                ll hm1 = 1000000*(i+j+k);
                ll hm2 = i*j*k-1000000;
                if(hm1%hm2!=0) continue;
                ll l = hm1/hm2;
                ll product = i*j*k*l;
                ll sum = i+j+k+l;
                if(i+j+k+l > 2000 || l < k) continue;

                if(sum*1000000==product){
                    cout << (double) i/100 << " " << (double) j/100 << " " << (double) k/100 << " " << (double) l/100 << "\n";
                }
                
            }
        }
    }
    return 0;
}