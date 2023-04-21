#include <bits/stdc++.h>
using namespace std;

#define ll long long

class UnionFind{
    private:
        vector<ll> p, setSize;

    public:
        UnionFind(ll n){
            p.assign(n, 0); setSize.assign(n,1);
            for(ll i = 0; i < n; i++) p[i] = i;
        }

        ll findSet(ll k){return (p[k]==k)?k:(p[k]=findSet(p[k]));}
        ll findSize(ll k){return setSize[findSet(k)];}
        void Union(ll x, ll y){
            if(findSet(x)==findSet(y)) return;

            x = findSet(x); y = findSet(y);

            if(setSize[x] > setSize[y]) swap(x, y);

            p[x] = y;

            setSize[y] += setSize[x];
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll n,m;

    while(cin >> n >> m && n){
        UnionFind UF(n);
        

        for(ll i = 0; i < m; i++){
            ll k; cin >> k;
            ll h; cin >> h;
            
            for(ll j = 1; j < k; j++){
                ll temp; cin >> temp;
                UF.Union(h, temp);
            }
        }

        cout << UF.findSize(0) << "\n";


    }
    return 0;
}