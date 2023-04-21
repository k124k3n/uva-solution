#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> un;

bool check(ll n, unordered_map<ll, bool> k){
    unordered_map<ll, bool> hi;
    hi = k;
    if(n < 10000) hi[0] = true;
    ll temp = n;
    while(temp > 0){
        ll mod = temp%10;
        if(hi[mod]){
            return false;
        }

        hi[mod] = true;
        temp /= 10;
    }

    return true;
}

void gen(){
    for(ll i = 1234; i <= 49382; i++){
        unordered_map<ll, bool> temp;
        if(check(i, temp)) un.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    gen();
    
    ll n; ll cs = 0;

    while(cin >> n && n){
        if(++cs != 1){
            cout << "\n";
        }

        ll sum = 0;

        for(auto x: un){
            ll bil = x*n;
            if(bil < 10000) continue;
            unordered_map<ll, bool> hm;
            ll temp = x;
            if(x < 10000) hm[0] = true;
            while(temp > 0){
                ll mod = temp%10;
                hm[mod] = true;
                temp /= 10;
            }

            if(check(bil, hm)){
                ++sum;
                cout << bil << " / ";
                if(x < 10000) cout << "0";
                cout << x << " = " << n << "\n";
            }
        }

        if(sum==0) cout << "There are no solutions for " << n << ".\n";
    }
    return 0;
}