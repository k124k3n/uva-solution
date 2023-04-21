#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dt{
    ll st, en;

    dt(ll _st, ll _en){
        st = _st;
        en = _en;
    }

    friend bool operator<(dt a, dt b){
        if(a.en != b.en) return a.en<b.en;
        else return a.st < b.st;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    ll a, b;

    vector<dt> li;
    while(cin >> a >> b){
        if(a==0&&b==0){
            sort(li.begin(), li.end());
            // do the whole job!
            ll sum = 0;
            ll x = 0, y = 0;
            for(auto &[st, en]: li){
                // cout << st << " " << en << "\n";
                if(st >= y){
                    x = st;
                    y = en;
                    ++sum;
                }
            }

            cout << sum << "\n";
            li.clear();
        }
        else li.emplace_back(a, b);
    }
    return 0;
}