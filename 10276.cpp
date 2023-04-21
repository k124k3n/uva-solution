#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[52];
void generate(){
    vector<ll> bil; unordered_map<ll, ll> index;
    bil.push_back(1);
    arr[1] = 1;
    index[1] = 0;

    ll k = 2;

    while(bil.size() <= 50){
        ll kud = bil.size() * bil.size();
        ll sel = abs(kud - k);

        if(sel==k || index[sel] == -1 || k >= kud){
            arr[bil.size()] = k-1;
            bil.push_back(k);
            index[k] = bil.size() - 1;
            k++;
            continue;
        }

        bil[index[sel]] = k;
        index[k] = index[sel];
        index[sel] = -1;

        k++;
    }




}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    generate();

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << arr[n] << "\n";
    }

    return 0;
}