#include <bits/stdc++.h>
using namespace std;

#define ll long long


class UnionFind{
    private:
        vector<ll> p; vector<ll> setSize; vector<ll> rank;
        ll manySet;

    public:

        UnionFind(ll n){
            p.assign(n,0);
            for(ll i = 0; i < n; i++){
                p[i] = i;
            }

            rank.assign(n, 0);
            setSize.assign(n, 1);
            manySet = n;
        }

    
        ll findSet(ll k){   
            return (p[k]==k)?(k):(p[k] = findSet(p[k]));
        }

        bool isSameSet(ll x, ll y){
            return (findSet(x)==findSet(y));
        }

        ll howMany(){return manySet;}

        ll Size(ll k){return setSize[k];}

        void unite(ll x, ll y){
            if(isSameSet(x, y)) return;
            x = findSet(x); y = findSet(y);
            if(rank[p[x]]>rank[p[y]]) swap(x, y);
            

            // rank[p[y]] += rank[p[x]];
            setSize[x] += setSize[y];
            p[x] = y;

            --manySet;
        }

        
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    UnionFind UF(n);

    ll q; cin >> q;

    for(ll i = 0; i < q; i++){
        char h; ll a, b; cin >> h >> a >> b;
        if(h=='=') UF.unite(a,b);
        else{
            if(UF.isSameSet(a, b)) cout << "yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}