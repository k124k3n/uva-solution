#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 998244353;

vector<ll> a, b, c, ab, ac, bc, abc;
vector<ll> al, bl, cl, abl, acl, bcl, abcl;
// vector<vector<ll>> &abt, &act, &bct, &abct;
vector<ll> abx, acx, bcx, abcx;
vector<ll> arr; // vector<vector<ll>> &st1, &st2, &x2, &l1, &l2;

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
            abx.assign(4*n, -1);
            acx.assign(4*n, -1);
            bcx.assign(4*n, -1);
            abcx.assign(4*n, -1);
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
                    // cout << l << " " << mid << " = " << lazy[now*2] << "prop\n";
                    // cout << mid+1 << " " << r << " = " << lazy[now*2+1] << "prop\n";
                }

                lazy[now] = -1;
            }
        }

        void update(ll now, ll l, ll r, ll i, ll j, vector<ll> &lazy, vector<ll> &st, ll val){
            prop(now, l, r, lazy, st);
            if(i > j) return;
            if(i > r || l > j) return;

            

            if(l >= i && j >= r){
                lazy[now] = val;
                prop(now, l, r, lazy, st);
                // cout << "INRANGE " << l << " " << r << " = " << st[now] << "\n";
                return;
            }

            ll mid = (l+r)/2;

            update(now*2, l, mid, i, min(mid, j), lazy, st, val);
            update(now*2+1, mid+1, r, max(mid+1, i), j, lazy, st, val);
            st[now] = ((st[now*2] % mod) + (st[now*2+1] % mod)) % mod;
            // cout << l << " " << r << " = " << st[now*2] << "+" << st[now*2+1] << "\n";
            // cout << l << " " << r << " = " << st[now] << "\n";
        }

        void update(ll now, ll l, ll r, ll i, ll j, vector<ll> &lazy, vector<ll> &lazy2, vector<ll> &st, vector<ll> &x, ll val){
            if(i > j) return;
            if(i > r || l > j) return;

            prop(now, l, r, lazy, st, x);
            prop(now, l, r, lazy2, x);

            if(l >= i && j >= r){
                lazy[now] = val;
                prop(now, l, r, lazy2, x);
                prop(now, l, r, lazy, st, x);
                
                cout << "INRANGE " << l << " " << r << " = " << st[now] << "\n";
                return;
            }

            ll mid = (l+r)/2;

            update(now*2, l, mid, i, min(mid, j), lazy, lazy2, st, x, val);
            update(now*2+1, mid+1, r, max(mid+1, i), j, lazy, lazy2, st, x, val);
            st[now] = ((st[now*2] % mod) + (st[now*2+1] % mod)) % mod;
            // cout << l << " " << r << " = " << st[now*2] << "+" << st[now*2+1] << "\n";
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
        cout << "A\n\n";
        
        st.update(1, 0, (n-1), l, r, al, a, x); // A

        cout << "AB\n";
        st.update(1, 0, (n-1), l, r, abl, bl, ab, b, x); // Bx
        st.update(1, 0, (n-1), l, r, abl, al, ab, a, y); // A(B+y) = AB + Ay
        cout << "end\n";
        cout << "ab = " << ab[1] << "\n";
        // st.update(1, 0, (n-1), l, r, acl, ac, c, x); // (A+x)C = AC + Cx
        // st.update(1, 0, (n-1), l, r, abcl, abc, bc, x); // (A+x)BC = ABC + BCx
        
        
        cout << "B\n\n";
        
        st.update(1, 0, (n-1), l, r, bl, b, y); // B
        
        // st.update(1, 0, (n-1), l, r, bcl, bc, c, y); // (B+y)C = BC + Cy
        // st.update(1, 0, (n-1), l, r, abcl, abc, ac, y); // AC(B+y) = ABC + ACy
        
        
        
        
            cout << "C\n";
            st.update(1, 0, (n-1), l, r, cl, c, z); // C
            // cout << "end\n\n";
            // st.update(1, 0, (n-1), l, r, acl, ac, a, z); // A(C+z) = AC + Az
            // cout << "end\n\n";
            // st.update(1, 0, (n-1), l, r, bcl, bc, b, z); // B(C+z) = BC + Bz
            // cout << "end\n\n";
            // st.update(1, 0, (n-1), l, r, abcl, abc, ab, z); // AB(C+z) = ABC + ABz
            // cout << "end\n\n";
        
        
        // update double
        cout << abc[1] << "\n";

    }
    return 0;
}