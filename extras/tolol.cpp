#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    map<string, vector<ll>> hi;
    hi["5"].push_back(9); hi["5"].push_back(10);
    for(auto x: hi["5"]){
        cout << x << " ";
    }
    return 0;
}