#include <bits/stdc++.h>
using namespace std;

#define ll long long

class UnionFind{
    private:
        vector<ll> p, setSize;

    public:
        UnionFind(ll n){
            p.assign(n+1,0); setSize.assign(n+1,1); 
            for(ll i = 1; i <= n; i++) p[i] = i;
        }
        
        ll findSize(ll k){return (setSize[findSet(k)]);}
        ll findSet(ll k){return (p[k]==k)?k:(p[k]=findSet(p[k]));}

        void Union(ll x, ll y){
            if(findSet(x)==findSet(y)) return;

            x = findSet(x); y = findSet(y);

            if(setSize[x] > setSize[y]) swap(x, y);

            setSize[y] += setSize[x];
            
            p[x] = y;



        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;
        
    while(t--){
        ll Max = 1;
        ll n,m; cin >> n >> m;
        UnionFind UF(n);

        for(ll i = 0; i < m; i++){
            ll a,b; cin >> a >> b;
            UF.Union(a, b);
            Max = max(Max, max(UF.findSize(a), UF.findSize(b)));
        }

        cout << Max << "\n";
    }
    
    return 0;
}