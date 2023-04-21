#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;
    

    while(t--){
        ll n,s,q; cin >> n >> s >> q;
        queue<ll> qu[n];
        ll mQ[n];
        stack<ll> car;
        ll sum = 0, tm = 0;
        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            mQ[i]=temp;
            sum += temp;
            for(ll j = 0; j < temp; j++){
                ll tempp; cin >> tempp;
                qu[i].push(tempp-1);
            }
        }

        ll sitr = 0;

        while(sum>0){
            while(!car.empty()){ // unload
                if(car.top() == sitr){
                    --sum;
                }
                else if(qu[sitr].size() == q){
                    break;
                }
                else{
                    qu[sitr].push(car.top());
                }

                ++tm;
                car.pop();
            }

            while(car.size() < s && !qu[sitr].empty()){ // load
                car.push(qu[sitr].front());
                qu[sitr].pop();
                ++tm;
            }

            if(sum!=0) tm += 2;
            sitr = (sitr+1)%n;
        }

        cout << tm << "\n";
    }
    return 0;
}