#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree{
    private:
        vector<ll> lazy, st; ll n;

        void prop(ll now, ll L, ll R){
            if(L > R) return;
            if(lazy[now]==2){ // flip
                st[now] = (R-L+1) - st[now];

                if(L!=R){
                    ll mid = (L+R)/2;
                    prop((now<<1), L, mid);
                    prop((now<<1) + 1, mid+1, R);

                    lazy[(now << 1)] = lazy[now];
                    lazy[(now << 1)+1] = lazy[now];
                }

                lazy[now] = -1;
            }

            else if(lazy[now] != -1){
                if(lazy[now]){ // == 1
                    st[now] = (R-L+1);
                }

                else{
                    st[now] = 0;
                }

                if(L!=R){
                    ll mid = (L+R)/2;
                    lazy[(now << 1)] = lazy[now];
                    lazy[(now << 1)+1] = lazy[now];
                }

                lazy[now] = -1;
            }
        }

    public:
        vector<ll> arr;
        void build(ll now, ll L, ll R){
            if(L==R){
                st[now] = arr[L];
                return;
            }

            ll mid = (L+R)/2;

            build((now << 1), L, mid);
            build((now << 1)+1, mid+1, R);

            st[now] = st[(now << 1)] + st[(now << 1)+1];
        }

        SegmentTree(ll n, vector<ll> &t){
            this->n = n;
            lazy.assign(4*n, -1);
            st.assign(4*n, 0);
            arr = t;

            build(1, 0, (this->n - 1));
        }

        void update(ll now, ll L, ll R, ll i, ll j, ll val){
            prop(now, L, R);
            if(i > j) return;
            if(i > R || L > j) return;

            if(L >= i && j >= R){
                lazy[now] = val;
                prop(now, L, R);
                return;
            }

            ll mid = (L+R)/2;

            update((now<<1), L, mid, i, min(j, mid), val);
            update((now<<1)+1, mid+1, R, max(mid+1, i), j, val);
            st[now] = st[(now << 1)] + st[(now << 1)+1];

            // cout << L << " " << R << " = " << st[now] << "\n";
        }

        ll RSQ(ll now, ll L, ll R, ll i, ll j){
            prop(now, L, R);
            if(i > j) return 0;
            if(i > R || L > j) return 0;

            if(L >= i && j >= R){
                return st[now];
            }

            ll mid = (L+R)/2;

            ll left = RSQ((now<<1), L, mid, i, min(j, mid));
            ll right = RSQ((now<<1)+1, mid+1, R, max(mid+1, i), j);
            return (left+right);
        }


};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;
    vector<ll> arr;
    arr.assign(1025000, 0);
    ll cs = 0;
    while(t--){
        cout << "Case " << ++cs << ":\n";
        ll m; cin >> m;
        
        ll idx = 0;
        SegmentTree st(1025000, arr);
        while(m--){
            ll t; cin >> t;
            string temp; cin >> temp;
            while(t--){
                for(ll i = 0; i < temp.length(); i++){
                    arr[idx++] = temp[i] - '0';
                }
            }
        }

        st.arr = arr;
        st.build(1, 0, (idx-1));

        ll n = idx;
        ll q; cin >> q;
        ll qc = 0;
        ll hm = 0;
        while(q--){

            // cout << ++hm << "\n";
            char com; ll a,b; cin >> com >> a >> b;

            if(com == 'F'){ // to 1
                st.update(1,0,(n-1),a,b,1);
            }

            else if(com == 'E'){ // to 0
                st.update(1,0,(n-1),a,b,0);
            }

            else if(com == 'I'){ // flip
                st.update(1,0,(n-1),a,b,2);
            }

            else{ // print RSQ
                cout << "Q" << ++qc << ": ";
                cout << st.RSQ(1,0,(n-1),a,b) << "\n";
            }
        }

    }

    return 0;
} 
