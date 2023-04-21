#include <iostream>
#include <algorithm> // sort()
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <map>
#include <sstream>
#include <cstring> // memset() toupper()
#include <cmath> // sqrt(), abs()
#include <numeric> // lcm(), gcd()
#include <iomanip> // setprecision()
#include <stdlib.h> // use labs for ll/ull, not abs
#include <unordered_map>
#include <climits> // LLONG_MAX, ULLONG_MAX, INT_MAX
#include <sstream>

using namespace std;

#define ll long long

class UnionFind{
    private:
        vector<ll> p, setSize, sum; unordered_map<ll, set<ll>> child;

    public:

        UnionFind(ll n){
            p.assign(n+1, 0); setSize.assign(n+1, 1); sum.assign(n+1,0);
            for(ll i = 1; i <= n; i++){
                p[i] = i;
                sum[i] = i;
            }

        }

        ll findSet(ll k){
//        	return (p[k]==k)?k:(findSet(p[k]));
			if(p[k]==k) return k;
			else{
					// child[p[k]].erase(k);
					// child[p[p[k]]].insert(k);
					// 	p[k] = p[p[k]];
					
					
					return findSet(p[k]);
			}
    	}
        	
        ll findSum(ll k){return sum[findSet(k)];}
        ll findSize(ll k){
            return setSize[findSet(k)];
        }
        
        void Union(ll x, ll y){

            x = findSet(x); y = findSet(y);
            if(x==y) return;
            if(findSize(x) > findSize(y)) swap(x,y);
            sum[y] += sum[x];
            setSize[y] += setSize[x];
            p[x] = y;
            child[y].insert(x);
            sum[x] = sum[y];
            setSize[x] = setSize[y];

        }

        void nUnion(ll x, ll y){
            ll px = findSet(x);
            if(findSize(px)==1){
                Union(x,y);
                return;
            }
            y = findSet(y);
            
            if(px==y) return;
            
            if(px == x){
                if(child[x].size()==0){
                    Union(x,y);
                    return;
                }
            	ll par = findSet(x);
            	sum[par] -= x;
          	  --setSize[par];
          	  
          	  par = *(child[x].begin());
          	  ll boo = findSet(x);
          	  sum[par] = sum[boo];
          	  setSize[par] = setSize[boo];
          	  p[par] = par;
          	  for(auto k: child[x]){
          	  	if(k==par) continue;
          	  	p[k] = par;
          	  	child[par].insert(k);
          	  }
          	  
          	  child[x].clear();
            }
            
            else{
            	ll par = findSet(x);
            	p[par] = par;
            	sum[par] -= x;
                --setSize[par];
                for(auto k: child[x]){
                    if(k==par) continue;
          	  	    p[k] = par;
          	  	    child[par].insert(k);
          	    }
                child[par].erase(x);
                child[x].clear();
            }
            
            sum[findSet(y)] += x;
            p[x] = findSet(y);
            child[y].insert(x);
            ++setSize[y];
            sum[x] = sum[y];
            setSize[x] = setSize[y];
        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    ll n,m;
    ll hm = 0, len = 0;
    while(cin >> n >> m){
        ++len;
        UnionFind UF(n);

        for(ll i = 0; i < m; i++){
            ++len;
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
//                if(UF.findSize(a)==2 && UF.findSum(a)==109){
//                	cout << n << " " << m << " " << len << ":(\n";
//                }
                cout << UF.findSize(a) << " " << UF.findSum(a) << "\n";
            }
        }
    }
    return 0;
}