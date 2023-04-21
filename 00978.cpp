#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){1014
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;

    while(n--){
        ll B,sg,sb; cin >> B >> sg >> sb;
        multiset<ll> g, b;

        for(ll i = 0; i < sg; i++){
            ll temp; cin >> temp;
            g.insert(temp);
        }

        for(ll i = 0; i < sb; i++){
            ll temp; cin >> temp;
            b.insert(temp);
        }

        while(g.size()>0&&b.size()>0){
            ll f = min(B, min((ll)g.size(), (ll)b.size()));
            queue<ll> qG,qB;

            // for(auto x: g){
            //     cout << x << " ";
            // } cout << "\n";

            // for(auto x: b){
            //     cout << x << " ";
            // } cout << "\n";
            for(ll i = 0; i < f; i++){
                ll bigG = *(g.rbegin());
                ll bigB = *(b.rbegin());
                if(bigG>bigB){
                    qG.push(bigG-bigB);
                }

                else if(bigG<bigB){
                    qB.push(bigB-bigG);
                }

                g.erase(g.find(bigG)); b.erase(b.find(bigB));
            }
            
            while(!qG.empty()){
                g.insert(qG.front());
                qG.pop();
            }

            while(!qB.empty()){
                b.insert(qB.front());
                qB.pop();
            }

        }

        if(g.size()>0){
            cout << "green wins\n";
            while(!g.empty()){
                cout << *(g.rbegin()) << "\n";
                g.erase(g.find(*g.rbegin()));
            }
        }
        else if(b.size()>0){
            cout << "blue wins\n";
            while(!b.empty()){
                cout << *(b.rbegin()) << "\n";
                b.erase(b.find(*b.rbegin()));
            }

            
        }
        else{
            cout << "green and blue died\n";
            
        }
        if(cin.good()) cout << "\n";

    }
    return 0;
}