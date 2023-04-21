#include <bits/stdc++.h>
using namespace std;

#define ll long long

string arr[200];
ll m,n,q;

ll process(ll a, ll b){
    ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    ll dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    ll sum = LLONG_MAX;

    // if(a < 0 || b < 0 || a >= m || b >= n) return 0;
    for(ll i = 0; i < 8; i++){
        ll x = a+dx[i], y = b+dy[i];

        char init = arr[a][b];
        ll tr = 0;

        while(x >= 0 && y >= 0 && x < m && y < n){
            if(arr[x][y] != init) break;
            tr++;

            x += dx[i]; y += dy[i];
        }
        sum = min(sum, tr);
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t; cin >> t;

    while(t--){
        cin >> m >> n >> q;
        cout << m << " " << n << " " << q << "\n";
        for(ll i = 0; i < m; i++){
            cin >> arr[i];
        }

        while(q--){
            ll x,y; cin >> x >> y;
            cout << 1 + 2*process(x, y) << "\n";
        }
    }
    return 0;
}