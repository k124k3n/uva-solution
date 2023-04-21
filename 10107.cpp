#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<ll> hi;
    ll x;

    while(cin >> x){
        hi.push_back(x);
        if(hi.size()%2){
            ll h = (hi.size())/2;
            nth_element(hi.begin(), hi.begin()+h, hi.end());
            cout << hi[hi.size()/2] << "\n";
        }

        else{
            ll h = hi.size()/2;
            nth_element(hi.begin(), hi.begin()+h, hi.end());
            ll a = hi[h];
            nth_element(hi.begin(), hi.begin()+h-1, hi.end());
            cout << (a + hi[h-1])/2 << "\n";
        }
    }
    return 0;
}