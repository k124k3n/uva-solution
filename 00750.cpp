#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> l;
vector<ll> temp;
bool pl[30] = {false}, col[9] = {false};
unordered_map<ll, bool> xy,yx;

void brute(ll d){
    if(d==9){
        vector<ll> t;
        for(auto x: temp){
            t.push_back(x);
            // cout << x << " ";
        } //cout << "\n";

        l.push_back(t);
        return;
    }

    for(ll i = 1; i <= 8; i++){
        if(pl[i+d]||yx[i-d]||col[i]||xy[d-i]){
            // cout << d << " " << i << "gagal\n";
            // cout << "THIS: " << i+d << " " << abs(i-d) << " " << i << "\n";
            continue;
        }
        pl[i+d] = yx[i-d] = col[i] = xy[d-i] = true;
        // cout << i+d << " " << abs(i-d) << " " << i << "\n";
        // cout << pl[i+d] << " " << sol[abs(i-d)] << ' ' << col[i] << "\n";
        temp.push_back(i);
        // cout << "HALO" << d << " " << i << "\n";
        brute(d+1);
        // cout << "end\n";
        temp.pop_back();
        pl[i+d] = yx[i-d] = col[i] = xy[d-i] = false;
    }

}

int main(){
    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    brute(1);

    ll t; cin >> t;
    for(ll m = 0; m < t; m++){

        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        ll x,y; cin >> x >> y;
        ll cs = 0;
        for(auto h: l){
            if(h[y-1]!=x) continue;
            printf("%2lld      ", ++cs);
            for(ll i = 0; i < h.size(); i++){
                cout << h[i];

                if(i!=(h.size()-1)) cout << " ";
            } cout << "\n";
        } 
        
        if(m!=(t-1))cout << "\n";

    }
    return 0;
}