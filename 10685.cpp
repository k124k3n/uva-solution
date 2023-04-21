#include <bits/stdc++.h>
using namespace std;

#define ll long long

class UnionFind{
    private:
        vector<ll> p, setSize;

    public:
        UnionFind(ll n){
            p.assign(n, 0); setSize.assign(n, 1);
            for(ll i = 0; i < n; i++) p[i] = i;
        }

        ll maxSet = 1;

        ll findSet(ll k){return (p[k]==k)?k:(p[k]=findSet(p[k]));}

        void Union(ll x, ll y){
            if(findSet(x)==findSet(y)) return;
            if(setSize[x] > setSize[y]) swap(x,y);

            x = findSet(x); y = findSet(y);
            setSize[y] += setSize[x];
            maxSet = max(maxSet, setSize[y]);
            p[x] = y;


        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll c,r;
    while(cin >> c >> r && c){
        UnionFind UF(c);
        unordered_map<string, ll> li;
        for(ll i = 0; i < c; i++){
            string hi; cin >> hi;
            li[hi] = i;
        }

        for(ll i = 0; i < r; i++){
            string a,b; cin >> a >> b;
            ll x = li[a], y = li[b];
            UF.Union(x,y);
        }

        cout << UF.maxSet << "\n";
    }
    
    return 0;
}