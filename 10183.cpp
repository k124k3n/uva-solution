#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll board[5][5];
unordered_map<ll, pair<ll,ll>> hi;
ll ud[5] = {0}, lr[5] = {0}, ldig = 1, rdig = 1;

void check(ll hm){
    if(hi.find(hm) == hi.end()) return;
    ll a = hi[hm].first;
    ll b = hi[hm].second;
    ++ud[a], ++lr[b];
    if(a == b) ++ldig;
    else if((a+b) == 4) ++rdig;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    board[2][2] = -1;
    while(t--){
        hi.clear();
        bool completed = false;
        for(ll i = 0; i < 5; i++){
            lr[i] = 0;
            ud[i] = 0;
        }

        ++lr[2], ++ud[2];
        ldig = 1, rdig = 1;

        for(ll i = 0; i < 5; i++){
            for(ll j = 0; j < 5; j++){
                if(i==2&&j==2) continue;
                cin >> board[i][j];
                hi[board[i][j]] = make_pair(i,j);
                

            }
        }

        for(ll i = 0; i < 75; i++){
            ll temp; cin >> temp;
            check(temp);
            if(completed) continue;
            for(ll j = 0; j < 5; j++){
                if(lr[j]==5 || ud[j]==5 || ldig==5 || rdig==5){
                    cout << "BINGO after " << i+1 << " numbers announced\n";
                    completed = true;
                    break;
                }
            }
        }

    }

    return 0;
}