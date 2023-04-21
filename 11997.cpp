#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll k;

    while(cin >> k){
        ll A1[k], A2[k];
        for(ll i = 0; i < k; i++) cin >> A1[i];
        sort(A1, A1+k);

        for(ll i = 1; i < k; i++){
            priority_queue<ll> pq;
            
            for(ll j = 0; j < k; j++){                
                cin >> A2[j];
            }

            sort(A2, A2+k);

            for(ll j = 0; j < k; j++){
                pq.push(A1[j] + A2[0]);
            }

            for(ll j = 0; j < k; j++){
                if(A1[j] >= pq.top()) break;
                for(ll m = 1; m < k; m++){
                    ll sum = A1[j] + A2[m];

                    if(sum >= pq.top()) break;
                    else{
                        pq.pop();
                        pq.push(sum);
                    }

                }
            }

            for(ll j = k-1; j >= 0; j--){
                A1[j] = (pq.top());
                // cout << A1[j] << " ";
                pq.pop();
            }

            // cout << "\n";
        }

        for(ll i = 0; i < k; i++){
            cout << A1[i];
            if(i!=(k-1)) cout << " ";
        } cout << "\n";
    }
    
    return 0;
}