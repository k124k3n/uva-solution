#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 998244353;

vector<ll> a, b, c, ab, ac, bc, abc;
vector<ll> al, bl, cl, abl, acl, bcl, abcl;
vector<ll> arr;

class SegmentTree{
    public:
        SegmentTree(ll n){
            a.assign(4*n, 0);
            b.assign(4*n, 0);
            c.assign(4*n, 0);
            ab.assign(4*n, 0);
            ac.assign(4*n, 0);
            bc.assign(4*n, 0);
            abc.assign(4*n, 0);
            al.assign(4*n, -1);
            bl.assign(4*n, -1);
            cl.assign(4*n, -1);
            abl.assign(4*n, -1);
            acl.assign(4*n, -1);
            bcl.assign(4*n, -1);
            abcl.assign(4*n, -1);

            // build(1, 0, (n-1), a);
            // build(1, 0, (n-1), b);
            // build(1, 0, (n-1), c);
            // build(1, 0, (n-1), a, b, ab);
            // build(1, 0, (n-1), a, c, ac);
            // build(1, 0, (n-1), b, c, bc);
            // build(1, 0, (n-1), a, b, c, abc);

        }

        void build(ll now, ll l, ll r, vector<ll> &st){
            if(l == r){
                st[now] = arr[l];
                return;
            }

            ll mid = (l+r)/2;

            build(now*2, l, mid, st);
            build(now*2+1, mid+1, r, st);
            st[now] = ((st[now*2] % mod) + (st[now*2+1] % mod)) % mod;
            cout << l << " " << r << " = " << st[now] << "\n";
        }

        void build(ll now, ll l, ll r, vector<ll> &x, vector<ll> &y, vector<ll> &st){
            if(l == r){
                st[now] = ((x[l]%mod) * (y[l]%mod)) % mod;
                return;
            }

            ll mid = (l+r)/2;

            build(now*2, l, mid, x, y, st);
            build(now*2+1, mid+1, r, x, y, st);
            st[now] = ((st[now*2] % mod) + (st[now*2+1] % mod)) % mod;
        }

        void build(ll now, ll l, ll r, vector<ll> &x, vector<ll> &y, vector<ll> &z, vector<ll> &st){
            if(l == r){
                st[now] = (x[l]%mod) * (y[l]%mod) * (z[l]%mod);
                return;
            }

            ll mid = (l+r)/2;

            build(now*2, l, mid, x, y, z, st);
            build(now*2+1, mid+1, r, x, y, z, st);
            st[now] = ((st[now*2] % mod) + (st[now*2+1] % mod)) % mod;
        }

        ll RSQ(){
            return abc[1];
        }

        void prop(ll now, ll l, ll r, vector<ll> &lazy, vector<ll> &st){ // 1
            if(lazy[now]!=-1){
                st[now] = ((st[now]%mod)+(((r-l+1)%mod)*(lazy[now]%mod) % mod)) % mod;
                
                ll mid = (l+r)/2;

                if(l != r){
                    prop(now*2, l, mid, lazy, st);
                    prop(now*2+1, mid+1, r, lazy, st);

                    lazy[now*2] = lazy[now];
                    lazy[now*2+1] = lazy[now];
                }

                lazy[now] = -1;
            }
        }

        void prop(ll now, ll l, ll r, vector<ll> &lazy, vector<ll> &st, vector<ll> &x){ // 2
            if(lazy[now]!=-1){
                st[now] = ((st[now]%mod)+((x[now]%mod)*(lazy[now]%mod) % mod)) % mod;
                
                ll mid = (l+r)/2;

                if(l != r){
                    prop(now*2, l, mid, lazy, st, x);
                    prop(now*2+1, mid+1, r, lazy, st, x);

                    lazy[now*2] = lazy[now];
                    lazy[now*2+1] = lazy[now];
                }

                lazy[now] = -1;
            }
        }

        void update(ll now, ll l, ll r, ll i, ll j, vector<ll> &lazy, vector<ll> &st, ll val){
            if(i > j) return;
            if(i > r || l > j) return;

            prop(now, l, r, lazy, st);

            if(l >= i && j >= r){
                lazy[now] = val;
                prop(now, l, r, lazy, st);
                cout << "INRANGE " << l << " " << r << " = " << st[now] << "\n";
                return;
            }

            ll mid = (l+r)/2;

            update(now, l, mid, i, min(mid, j), lazy, st, val);
            update(now, mid+1, r, max(mid+1, i), j, lazy, st, val);
            st[now] = ((st[now*2] % mod) + (st[now*2+1] % mod)) % mod;

            cout << l << " " << r << " = " << st[now] << "\n";
        }

        void update(ll now, ll l, ll r, ll i, ll j, vector<ll> &lazy, vector<ll> &st, vector<ll> &x, ll val){
            if(i > j) return;
            if(i > r || l > j) return;

            prop(now, l, r, lazy, st);

            if(l >= i && j >= r){
                lazy[now] = val;
                prop(now, l, r, lazy, st, x);
                cout << "INRANGE " << l << " " << r << " = " << st[now] << "\n";
                return;
            }

            ll mid = (l+r)/2;

            update(now, l, mid, i, min(mid, j), lazy, st, x, val);
            update(now, mid+1, r, max(mid+1, i), j, lazy, st, x, val);
            st[now] = ((st[now*2] % mod) + (st[now*2+1] % mod)) % mod;
            cout << l << " " << r << " = " << st[now] << "\n";
        }


};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n,q; cin >> n >> q; 
    arr.assign(n, 0);
    SegmentTree st(n);

    while(q--){
        ll l, r, x, y, z; cin >> l >> r >> x >> y >> z;
        --l, --r;
        // update individual

        cout << "AB\n\n";
        st.update(1, 0, (n-1), l, r, abl, ab, b, x); // (A+x)(B+y) = AB + Ay + x(B+y)

        cout << "A\n\n";
        st.update(1, 0, (n-1), l, r, al, a, x); // A = (A+x)
        cout << "B\n\n";
        st.update(1, 0, (n-1), l, r, bl, b, y); // B = (B+y)
        cout << "C\n\n";
        st.update(1, 0, (n-1), l, r, cl, c, z); // C = (C+z)

        // update double
        
        cout << "AC\n\n";
        st.update(1, 0, (n-1), l, r, acl, ac, c, x); // (A+x)(C+y) = AC + Ay + Cx + xy
        st.update(1, 0, (n-1), l, r, acl, ac, a, z); // A(C+z) = AC + Az

        cout << "BC\n\n";
        st.update(1, 0, (n-1), l, r, bcl, bc, c, y); // (B+y)C = BC + Cy
        st.update(1, 0, (n-1), l, r, bcl, bc, b, z); // B(C+z) = BC + Bz

        // update triple
        st.update(1, 0, (n-1), l, r, abcl, abc, bc, x); // (A+x)BC = ABC + BCx
        st.update(1, 0, (n-1), l, r, abcl, abc, ac, y); // AC(B+y) = ABC + ACy
        st.update(1, 0, (n-1), l, r, abcl, abc, ac, z); // AB(C+z) = ABC + ABz

        cout << abc[1] << "\n";

    }
    return 0;
}