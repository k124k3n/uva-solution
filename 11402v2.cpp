#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll tme = 0;

class SegmentTree{
    private:
        vector<ll> st, lazy, flazy, all;
        string arr;
        
        /*
            
        */
        void propagate(ll now, ll L, ll R){
            if(lazy[now]!=-1){
                all[now] = lazy[now];
                if(!all[now]){ // === 0
                    st[now] = 0;
                    // cout << L << " " << R << " = " << 0 << "prop\n";
                }

                else{
                    st[now] = (R-L+1);
                    // cout << L << " " << R << " = " << st[now] << "prop\n";
                }

                if(L!=R){
                    ll mid = (L+R)/2;
                    checkprop(now*2, L, mid); // jika ada
                    lazy[now*2] = lazy[now];
                    
                    checkprop(now*2+1, mid+1, R); // jika ada
                    lazy[now*2+1] = lazy[now];
                    
                    // cout << L << " " << mid << " propagated\n";
                    // cout << mid+1 << " " << R << " propagated\n";
                }

                lazy[now] = -1;
                // ordit[now] = -1;
            }

            // cout << L << " " <<  R << " = " << st[now] << "\n"; 
        }

        void vprop(ll now, ll L, ll R){
            if(flazy[now]!=-1){
                st[now] = (R-L+1) - st[now];
                // cout << L << " " << R << " = " << st[now] << "flippp\n"; 
                if(all[now]!=-1) all[now] = (0-all[now]);
                if(L!=R){
                    // ll bye = ++tme;
                    ll mid = (L+R)/2;
                    checkprop(now*2, L, mid); // jika ada
                    flazy[now*2] = 1;
                    // flipt[now*2] = bye;
                    checkprop(now*2+1, mid+1, R); // jika ada
                    flazy[now*2+1] = 1;
                    // flipt[now*2+1] = bye;
                }

                flazy[now] = -1;
                // flipt[now] = -1;
            }
        }

        
        void build(ll now, ll L, ll R){
            if(L > R) return;

            if(L==R){
                all[now] = arr[L] - '0';
                st[now] = arr[L] - '0';
                return;
            }

            ll mid = (L+R)/2;

            build(now*2, L, mid);
            build(now*2+1, mid+1, R);

            if(all[now*2]==all[now*2+1] && all[now*2]!=-1) all[now] = all[now*2+1];
            st[now] = st[now*2] + st[now*2+1];
            // cout << L << " " << R << " = " << st[now] << "\n";
        }


        void checkprop(ll now, ll L, ll R){
            propagate(now, L, R);
                // cout << "plz prop " << L << " " << R << "\n";
            vprop(now, L, R);
        }

    public:
        SegmentTree(ll n, string t){
            arr.assign(n+1, 0);
            st.assign(4*n, -1);
            lazy.assign(4*n, -1);
            flazy.assign(4*n, -1);
            all.assign(4*n, -1);
            arr = t;
            build(1, 0, n-1); // check passed
        }

        void update(ll now, ll L, ll R, ll i, ll j, ll val){ // non-flip
            checkprop(now, L, R);

            if(i > j) return;
            if(i > R || L > j) return;    //  outside

            if(L >= i && j >= R){           //  inside
                lazy[now] = val;
                // ordit[now] = ++tme;
                checkprop(now, L, R);
                // cout << L << " " <<  R << " = " << st[now] << "  IN RANGE "  << val << "\n"; 
                return; // FATALLLL!!! GABOLEH RETURN LGSG,, ADA YG GAK KEUPDATE
            }
            
            // partially outside
            ll mid = (L+R)/2;

            update(now*2, L, mid, i, min(mid, j), val);
            update(now*2+1, mid+1, R, max(mid+1, i), j, val);

            if(L!=R && all[now*2]==all[now*2+1] && all[now*2] != -1) all[now] = all[now*2];
            st[now] = st[now*2] + st[now*2+1];
            // cout << L << " " <<  R << " = " << st[now] << "\n"; 
        }

        void flip(ll now, ll L, ll R, ll i, ll j){ // FLIP
            checkprop(now, L, R);

            if(i > j) return;
            if(i > R || L > j) return;    //  outside

            if(L >= i && j >= R){           //  inside
                // flipt[now] = ++tme;
                flazy[now] = 1;
                
                checkprop(now, L, R);
                // cout << L << " " <<  R << " = " << st[now] << "IN FLIP RANGE\n";
                 
                return; // FATALLLL!!! GABOLEH RETURN LGSG,, ADA YG GAK KEUPDATE
            }
            
            // partially outside
            ll mid = (L+R)/2;

            flip(now*2, L, mid, i, min(mid, j));
            flip(now*2+1, mid+1, R, max(mid+1, i), j);
            if(L != R && all[now*2]==all[now*2+1] && all[now*2] != -1) all[now] = all[now*2];
            st[now] = st[now*2] + st[now*2+1];
            // cout << L << " " <<  R << " = " << st[now] << "FLIP PARTIAL\n"; 
        }


        ll RSQ(ll now, ll L, ll R, ll i, ll j){
            checkprop(now, L, R);
            if(i > j) return 0;
            if(L > j || i > R) return 0;

            if(L >= i && j >= R){ // fully inside
                return st[now]; // BETA TEST
                // cout << i << " " << j << " = " << st[now] << " FINALLY INSIDE \n";
            }

            ll mid = (L+R)/2;

            ll lsub = RSQ(now*2, L, mid, i, min(j, mid));
            ll rsub = RSQ(now*2+1, mid+1, R, max(mid+1, i), j);
            // cout << L << " " <<  R << " = " << i << " " << j << "\n"; 
            // cout << i << " " << min(j,mid) << " = " << lsub << "\n";
            // cout << max(mid+1, i) << " " << j << " = " << rsub << "\n";
            return (
                lsub+rsub
            );
        }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;

    ll cs = 0;
    while(t--){
        cout << "Case " << ++cs << ":\n";
        ll m; cin >> m;
        string s;
        while(m--){
            ll t; cin >> t;
            string temp; cin >> temp;
            while(t--) s += temp;
        }

        SegmentTree st(s.length(), s);
        ll n = s.length();
        ll q; cin >> q;
        ll qc = 0;
        while(q--){
            char com; ll a,b; cin >> com >> a >> b;

            if(com == 'F'){ // to 1
                // cout << a << " " << b << " to 1 ========================\n";
                st.update(1,0,(n-1),a,b,1);
                // cout << "end ========================\n";
            }

            else if(com == 'E'){ // to 0
                // cout << a << " " << b << " to 0 ========================\n";
                st.update(1,0,(n-1),a,b,0);
                // cout << "end ========================\n";
            }

            else if(com == 'I'){ // flip
                // cout << a << " " << b << " FLIP ========================\n";
                st.flip(1,0,(n-1),a,b);
                // cout << "end ========================\n";
            }

            else{ // print RSQ
                cout << "Q" << ++qc << ": ";
                // cout << "Q" << ++qc << ": ========================";
                // cout << a << " " << b << " RSQ ========================\n";
                cout << st.RSQ(1,0,(n-1),a,b) << "\n";
            }
        }

    }

    return 0;
}