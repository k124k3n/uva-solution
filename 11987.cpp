#include <bits/stdc++.h>
using namespace std;

#define ll long long

class UnionFind{
    private:
        vector<ll> p, setSize, sum;

    public:
        vector<ll> b;

        UnionFind(ll n){
            p.assign(n+1, 0); setSize.assign(n+1, 1); b.assign(n+1, 0); sum.assign(n+1,0);
            for(ll i = 1; i <= n; i++){
                p[i] = i;
                b[i] = i;
                sum[i] = i;
            }

        }

        ll findSet(ll k){return (p[k]==k)?k:(p[k]=findSet(p[k]));}
        ll findSum(ll k){return sum[findSet(k)];}
        ll findSize(ll k){
            // cout << k << " " << setSize[findSet(k)] << "\n";
            return setSize[findSet(k)];
        }
        void Union(ll x, ll y){
            x = findSet(x); y = findSet(y);
            if(x==y) return;

            sum[y] += sum[x];
            setSize[y] += setSize[x];
            p[x] = y;
            b[y] = x;

            sum[x] = sum[y];
            setSize[x] = setSize[y];

            for(ll i = 1; i <= sum.size()-1; i++){
                cout << "sum[" << i << "] = " << sum[i] << "\n";
                cout << "setSize[" << i << "] = " << setSize[i] << "\n";
            } cout << "\n";

            
            // cout << "setSize[" << x << "] = " << setSize[x] << "\n";
        }

        void nUnion(ll x, ll y){
            if(findSize(x)==1){
                Union(x,y);
                return;
            }

            if(findSet(x)==findSet(y)) return;
            y = findSet(y);
            sum[y] += x;
            sum[findSet(x)] -= x;
            ++setSize[y]; --setSize[findSet(x)];

            p[x] = y;

            if(x==findSet(x)) p[b[x]] = b[x];
            // b[y] = x;

            sum[x] = sum[y];
            setSize[x] = setSize[y];

            for(ll i = 1; i <= sum.size()-1; i++){
                cout << "sum[" << i << "] = " << sum[i] << "\n";
                cout << "setSize[" << i << "] = " << setSize[i] << "\n";
            } cout << "\n";

            // cout << "setSize[" << x << "] = " << setSize[x] << "\n";
            // if(x==findSet(x)){

            // }

        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ll n,m;

    while(cin >> n >> m){
        UnionFind UF(n);

        for(ll i = 0; i < m; i++){
            ll c,a,b; cin >> c;

            if(c==1){
                cin >> a >> b;
                UF.Union(a, b);
            }
            else if(c==2){
                cin >> a >> b;
                UF.nUnion(a, b);
            }

            else{
                cin >> a;
                cout << UF.findSize(a) << " " << UF.findSum(a) << "\n";
            }
        }

        // for(ll i = 1; i <= n; i++){
        //     cout << "b[" << i << "] = " << UF.b[i] << "\n";
        // }
    }
    return 0;
}