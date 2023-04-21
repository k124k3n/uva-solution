#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<ll, ll>> hi = {
    {0, 0}, {200, 2}, {29900, 3}, {49529900, 5}, {LLONG_MAX, 7}
};

vector<ll> watt = {
    0, 100, 9900, 990000
};

ll countWatt(ll mon){ // money to watt
    pair <ll, ll> k = {mon, 0};
    ll up = lower_bound(hi.begin(), hi.end(), k) - hi.begin();
    // cout << (mon - hi[up-1].first)/hi[up].second << " " << watt[max(0LL, up-1)] << "\n";
    if(hi[up].first == mon){
        return hi[up].first;
    }

    if(up == 4){
        return (mon-5247200)/5;
    }

    
    else return (mon - hi[up-1].first)/hi[up].second + watt[max(0LL, up-1)];
}

ll countPrice(ll W){
    ll sum = 0;
    ll i = 1;
    for(; i < 4 && W >= watt[i]; i++){
            sum += min(watt[i], W) * hi[i].second;
            W -= min(watt[i], W);
    }

    if(W > 0){
        sum += W * hi[i].second;
    }
    return sum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll a,b;

    while(cin >> a >> b && a){
        ll watt = countWatt(a); // sum of watts
        cout << watt << "\n";
        ll l = 0, r = ceil((double)countWatt(a)/2);
        bool found = false;
        while(l < r){
            ll mid = (l+r)/2;
            ll mp = countPrice(mid);
            ll lp = countPrice(watt-mid);
            if(abs(mp - lp) == b){
                found = true;
                cout << min(mp, lp) << " " << max(mp, lp) << "\n";
                break;
            }
            else if(abs(mp-lp) > b){
                l = mid+1;
            }

            else r = mid-1;
        }

        ll L = l;
        ll R = watt-l;

        ll mp = countPrice(watt-l);
        ll lp = countPrice(l);

        if(mp < lp){ // R < L
            swap(mp, lp);
            swap(L, R);
            cout << "swapped!\n";
        }


        
        pair <ll, ll> k = {mp, 0};
        ll up = upper_bound(hi.begin(), hi.end(), k) - hi.begin() - 1;
        ll pr = hi[up].second;

        pair <ll, ll> k1 = {lp, 0};
        ll up1 = upper_bound(hi.begin(), hi.end(), k1) - hi.begin() - 1;
        ll pr1 = hi[up1].second;

        while(countPrice(R)-countPrice(L) != b){
            cout << countPrice(R) << " " << countPrice(L) << "\n";
            --L;
            --R;
        }

        mp = countPrice(R);
        lp = countPrice(L);
        if(!found) cout << lp << " " << mp << "\n";
    }

    return 0;
}