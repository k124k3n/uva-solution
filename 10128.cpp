#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool used[10];
ll li[30][30][30];
vector<ll> temp;
ll l = 1, r = 1;

void brute(ll d){
    if(d==14) return;

    for(ll i = 1; i <= 13; i++){
        if(used[i]) continue;

        used[i] = true;
        temp.push_back(i);
        if(temp.size()>1){
            if(temp[temp.size()-2] < i){
                ++l;
                ++li[d][l][r];
                brute(d+1);
                --l;
            }

            else{
                ++r;
                ++li[d][l][r];
                brute(d+1);
                --r;
            }
        }

        else{
            ++li[d][l][r];
            brute(d+1);
        }

        used[i] = false;
        temp.pop_back();
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    brute(1);
    ll t; cin >> t;

    while(t--){
        ll n,a,b; cin >> n >> a >> b;
        cout << li[n][a][b] << "\n";
    }
    return 0;
}