#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    set<ll> w;

    set<set<ll>> com[300];
    unordered_map<ll, ll> per;

    w.insert(0);
    for(ll i = 1; i <= 20; i++){
        w.insert(i);
        w.insert(i*2);
        w.insert(i*3);
    }

    w.insert(50);

    for(auto x: w){
        for(auto y: w){
            for(auto z: w){
                ++per[x+y+z];
                set<ll> v;
                v.insert(x);
                v.insert(y);
                v.insert(z);
                com[x+y+z].insert(v);
            }
        }
    }

    ll k;

    while(cin >> k && k > 0){
        if(per[k]==0){
            cout << "THE SCORE OF " << k << " CANNOT BE MADE WITH THREE DARTS.\n";
        }

        else{
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << k << " IS " << com[k].size() << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << k << " IS " << per[k] << ".\n";
        }
        
        cout << "**********************************************************************\n";
    }


    cout << "END OF OUTPUT\n";
    return 0;
}