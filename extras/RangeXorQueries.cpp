#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree{
    private:
        vector<ll> lazy, st, arr; ll sz;

    public:

        void build(ll now, ll L, ll R){
            if(L > R) return;

            if(L==R){  // leaf
                st[now] = arr[L];
            }

            else{
                ll mid = (L+R)/2;
                build(now*2, L, mid);
                build(now*2+1, mid+1, R);
                st[now] = (st[now*2] ^ st[now*2+1]);
                // cout << L << " " << R << " = " << st[now] << "\n";

                // test passed
            }
        }


        SegmentTree(ll n, vector<ll> &t){
            
            lazy.assign(4*n, -1);
            st.assign(4*n, LLONG_MAX);
            arr.assign(4*n, LLONG_MAX);
            arr = t;
            
            build(1, 0, n-1);
        }

        

        ll RXQ(ll now, ll L, ll R, ll i, ll j){
            if(i > j) return 0;
            // propagate
            if(lazy[now]!=-1){ // propagate
                st[now] = lazy[now];
                if(L!=R){
                    lazy[now*2] = lazy[now];
                    lazy[now*2+1] = lazy[now];
                }
                lazy[now] = -1;
            }

            if(L >= i && j >= R) return st[now];

            // cout << L << " " << R << " = " << st[now] << "\n";

            ll mid = (L+R)/2;


            return (
                RXQ(now*2, L, mid, i, min(mid, j))
                ^
                RXQ(now*2+1, mid+1, R, max(i, mid+1), j)
            );

        }

        void update(ll now, ll L, ll R, ll i, ll j, ll val){
            if(i > j) return;

            if(lazy[now]!=-1){ // propagate
                st[now] = lazy[now];
                if(L!=R){
                    lazy[now*2] = lazy[now];
                    lazy[now*2+1] = lazy[now];
                }
                lazy[now] = -1;
            }

            if(L > j || i > R){ // outside
                return;
            }

            if(L >= i && j >= R){ // fully inside, jangan pecah lagi
                lazy[now] = val;
                return;
            }

            // jika partially inside
            ll mid = (L+R)/2;
            update(now*2, L, mid, i, min(j, mid), val);
            update(now*2+1, mid+1, R, max(i, mid+1), j, val);
            ll ls = (lazy[now*2] != -1) ? lazy[now*2] : st[now*2];
            ll rs = (lazy[now*2+1] != -1) ? lazy[now*2+1] : st[now*2+1];

            st[now] = (ls ^ rs);

        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll n,q; cin >> n >> q;
    vector<ll> arr; arr.assign(n+1, 0);

    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    SegmentTree st(n, arr);

    for(ll i = 0; i < q; i++){
        ll x, y; cin >> x >> y;
        

        
        cout << st.RXQ(1, 0, n-1, x-1, y-1) << "\n";
    }


    return 0;
}