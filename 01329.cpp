#include <bits/stdc++.h>
using namespace std;

#define ll long long

class UnionFind{
    private:
        vector<ll> p, setSize, sum;

    public:
        // vector<ll> sum;
        UnionFind(ll n){
            p.assign(n+1, 0); setSize.assign(n+1, 1); sum.assign(n+1, 0);
            for(ll i = 1; i <= n; i++){
                p[i] = i;
            }
        }

        ll findSet(ll k){
            if(p[k]==p[p[k]]) return p[k];
            sum[k] += sum[p[k]];
            if(p[p[k]] != p[k]) p[k] = p[p[k]];

            return (findSet(k));          
        }

        ll findSum(ll k){return(sum[k]);}

        void unite(ll x, ll y){
            p[x] = y;
            sum[x] = (abs(y-x)) % 1000;
            
            x = findSet(x);
            y = findSet(y);

            
            // cout << x << " " << y << "\n";
        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;

        UnionFind UF(n);

        char com;

        while(cin >> com && com != 'O'){
            ll a, b;

            if(com == 'E'){
                cin >> a;
                UF.findSet(a);
                cout << UF.findSum(a) << "\n";
            }

            else{
                cin >> a >> b;
                UF.unite(a,b);
            }
        }
    }
    return 0;
}