#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree{
    private:
        vector<ll> lazy, st, arr;

        void prop(ll now, ll L, ll R){
            if(lazy[now]!=-1){
                st[now] = lazy[now];
                if(L!=R){
                    ll mid = (L+R)/2;
                    prop(now*2, L, mid);
                    prop(now*2+1, mid+1, R);

                    lazy[now*2] = lazy[now];
                    lazy[now*2+1] = lazy[now];
                }

                lazy[now] = -1;
            }
        }

        void build(ll now, ll L, ll R){
            if(L > R) return;
            if(L==R){
                st[now] = arr[L];
                return;
            }

            ll mid = (L+R)/2;
            build(now*2, L, mid);
            build(now*2+1, mid+1, R);
            st[now] = min(st[now*2], st[now*2+1]);
            // cout << L << " " << R << " = " << st[now] << "\n";
        }

    public:
        SegmentTree(ll n, vector<ll> &t){
            lazy.assign(4*n,-1);
            st.assign(4*n,0);
            arr.assign(n+1,0);

            arr = t;

            build(1, 0, (n-1));
        }

        void update(ll now, ll L, ll R, ll i, ll j, ll val){
            
            if(i > j) return;
            if(i > R || L > j) return;

            prop(now, L, R);

            if(L >= i && j >= R){ // inside 
                lazy[now] = val;
                prop(now, L, R);
                return;
            }

            // partially inside
            ll mid = (L+R)/2;
            update(now*2, L, mid, i, min(j, mid), val);
            update(now*2+1, mid+1, R, max(i, mid+1), j, val);
            st[now] = min(st[now*2], st[now*2+1]);
        }

        ll RMQ(ll now, ll L, ll R, ll i, ll j){
            
            if(i > j) return LLONG_MAX;
            if(i > R || L > j) return LLONG_MAX;

            prop(now, L, R);

            if(L >= i && j >= R){ // inside 
                // cout << i << " " << j << " = " << st[now] << "IN RANGE\n";
                return st[now];
                
            }

            // partially inside
            ll mid = (L+R)/2;
            ll lsub = RMQ(now*2, L, mid, i, min(j, mid));
            ll rsub = RMQ(now*2+1, mid+1, R, max(i, mid+1), j);
            // cout << i << " " << j << " = " << lsub << " " << rsub << "\n";
            return min(lsub,rsub);
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll n,q; cin >> n >> q; vector<ll> arr;
    arr.assign(n, 0);

    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin.ignore(1000, '\n');

    SegmentTree st(n, arr);

    while(q--){
        string str; getline(cin, str);
        if(str.find("query")==0){
            str = str.substr(6, str.length()-7);
            // cout << str << "\n";

            ll L = stoi(str.substr(0, str.find(","))) - 1;
            ll R = stoi(str.substr(str.find(",")+1, str.length()-(str.find(",")+1))) -1;

            cout << st.RMQ(1, 0, (n-1), L, R) << "\n";
        }

        else{
            str = str.substr(6, str.length()-7);

            stringstream ss(str);
            vector<ll> pos;
            vector<ll> el;
            string temp;

            ll itr = 0;

            while(getline(ss, temp, ',')){
                pos.push_back(stoi(temp)-1);
                el.push_back(arr[stoi(temp)-1]);
            }

            ll sz = pos.size();

            for(ll i = 0; i < sz; i++){
                st.update(1, 0, (n-1), pos[(i-1+(sz*999))%sz], pos[(i-1+(sz*999))%sz], el[i%sz]);
                arr[pos[(i-1+(sz*999))%sz]] = el[i%sz];
                // cout << pos[(i-1+sz)%sz] << " " << el[i%sz] << "\n";
            }

        }
    }



    return 0;
}