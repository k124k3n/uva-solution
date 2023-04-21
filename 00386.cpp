#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool comp(vector<ll> a, vector<ll> b){
    if(a[1] != b[1]) return a[1] < b[1];
    else if(a[0] != b[0]) return a[0] < b[0];
    else return a[2] < b[2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<vector<vector<ll>>> hi(500, vector<vector<ll>>());

    for(ll i = 2; i <= 200; i++){
        for(ll j = i; j <= 200; j++){
            for(ll k = j; k <= 200; k++){
                ll ik = i*i*i;
                ll jk = j*j*j;
                ll kk = k*k*k;
                ll cb = cbrt(ik+jk+kk);
                ll cbk = cb*cb*cb;

                if(ik+jk+kk == cbk){
                    hi[cb].push_back({i, j, k});
                }
            }
        }
    }

    for(ll i = 2; i <= 200; i++){
        // sort(hi[i].begin(), hi[i].end(), comp);
        for(auto x: hi[i]){
            cout << "Cube = " << i << ", Triple = (" << x[0] << "," << x[1] << "," << x[2] << ")\n";
        }
    }
    return 0;
}