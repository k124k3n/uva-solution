#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll pos[200000];
ll g;

class SegmentTree{
    private:
        vector<ll> lazy, arr, st; ll n;

    public:
        void prop(ll now, ll L, ll R){
            if(lazy[now] != -1){
                st[now] = lazy[now];
                lazy[now] = -1;
            }
        }
        void build(ll now, ll L, ll R){
            if(L==R){
                st[now] = arr[L];
                // cout << L << " " << R << " = " << st[now] << "\n";
                return;
            }

            ll mid = (L+R)/2;

            build(now*2, L, mid);
            build(now*2+1, mid+1, R);

            st[now] = st[now*2] + st[now*2+1];

            // cout << L << " " << R << " = " << st[now] << "\n";
        }

        SegmentTree(ll n, vector<ll> &t){
            st.assign(4*n, 0);
            lazy.assign(4*n, -1);

            this->n = n;
            arr = t;

            build(1, 0, this->n - 1);
        }

        void update(ll now, ll L, ll R, ll i, ll j, ll val){
            prop(now, L, R);
            if(i > j) return;
            if(i > R || L > j) return;

            if(L>=i && j>=R){
                lazy[now] = val;
                prop(now, L, R);

                return;
            }

            ll mid = (L+R)/2;

            update(now*2, L, mid, i, min(j, mid), val);
            update(now*2+1, mid+1, R, max(i, mid+1), j, val);

            st[now] = st[now*2] + st[now*2+1];
        }

        ll RSQ(ll now, ll L, ll R, ll i, ll j){
            prop(now, L, R);
            if(i > j) return 0;
            if(i > R || L > j) return 0;

            if(L>=i && j>=R){
                return st[now];
            }

            ll mid = (L+R)/2;

            ll left = RSQ(now*2, L, mid, i, min(j, mid));
            ll right = RSQ(now*2+1, mid+1, R, max(i, mid+1), j);
            // cout << "left = " << left << ",, right = " << right << "\n";
            return (left+right);
        }

        
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t; cin >> t;

    while(t--){
        ll n,m; cin >> n >> m;
        g = max(n,m);

        vector<ll> arr;
        arr.assign(g*2, 0);
        ll k = 0;


        for(ll i = g; i < 2*g; i++){
            arr[i] = 1;
            pos[++k] = i;
        }


        ll itr = g;
        SegmentTree st(2*g, arr);

        for(ll i = 0; i < m; i++){
            ll temp; cin >> temp;

            
            cout << st.RSQ(1, 0, (2*g-1), 0, pos[temp]) - 1;
            st.update(1,0,(2*g-1), pos[temp], pos[temp], 0);
            pos[temp] = --itr;
            // cout << "pos[" << temp << "] = " << pos[temp] << "\n";
            st.update(1,0,(2*g-1), pos[temp], pos[temp], 1);
            if(i!=(m-1)) cout << " ";
            
        } cout << "\n";

    }
    return 0;
}
