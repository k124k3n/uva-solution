#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Point{
    ll x=-1, y=-1;

    Point(ll _x, ll _y){
        x = _x;
        y = _y;
    }
};

ll m,n;

bool f(ll x, ll y, vector<Point> &li, vector<string> A, ll depth){
    for(auto k: li){
        ll i = k.x, j = k.y;
        if(x+i >= n || y+j >= n || x+i < 0 || y+j < 0) return false;
        if(A[x+i][y+j] == '.') return false;
        A[x+i][y+j] = '.';
    }

    
    if(depth==1) return true;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(A[i][j] == '*' && f(i, j, li, A, depth+1)) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    

    while(cin >> n >> m && m){
        vector<Point> li;
        vector<string> A, B;
        A.assign(n, ""); B.assign(m, "");
        bool found = false;
        ll sum = 0, sum1 = 0;
        for(ll i = 0; i < n; i++){
            cin >> A[i];
            
            for(ll j = 0; j < n; j++){
                sum += (A[i][j] == '*');
            }
        } 

        Point p{-1,-1};
        for(ll i = 0; i < m; i++){
            cin >> B[i];
            
            for(ll j = 0; j < m; j++){
                if(B[i][j] == '*'){
                    if(p.x==-1){
                        p.x = i; p.y = j;
                    }

                    ++sum1;
                    li.emplace_back(i-p.x, j-p.y);
                }
                
            }
        }

        // cout << "\n";

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                if(f(i, j, li, A, 0)){
                    found = true;
                    break;
                }
            }
        }

        cout << ((sum1*2==sum) && (found)) << "\n";

    }

    return 0;
}