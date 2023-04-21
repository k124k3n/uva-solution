#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dt{
    ll l,w,h;
    dt(ll _l, ll _w, ll _h){
        l = _l;
        w = _w;
        h = _h;
    }
};

bool comp(dt a, dt b){
    if(a.h!=b.h) return a.h > b.h;
    ll va = a.l*a.w*a.h;
    ll vb = b.l*b.w*b.h;
    return va > vb;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;

    while(cin >> n && n){
        vector<dt> hi;
        for(ll i = 0; i < n; i++){
            ll l,w,h; cin >> l >> w >> h;
            hi.emplace_back(l,w,h);
        }

        sort(hi.begin(),hi.end(),comp);

        cout << hi[0].l*hi[0].w*hi[0].h << "\n";
    }
    return 0;
}