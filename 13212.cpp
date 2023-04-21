#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[1000020];
ll inv = 0;
ll n;
ll b[1000200];

void msort(ll l, ll r){
    if(l >= r) return;
    ll mid = (l+r)/2;
    msort(l, mid);
    msort(mid+1, r);

    ll left = l;
    ll right = mid+1;

    // ll b[r-l+1];
    ll bItr = 0;

    while(left <= mid && right <= r){
        if(arr[left] <= arr[right]){
            b[bItr++] = arr[left++];
        }

        else{
            b[bItr++] = arr[right++];
            inv += (mid-left+1);
        }
    }

    while(left<=mid){
        b[bItr++] = arr[left++];
        
    }

    while(right<=r) b[bItr++] = arr[right++];
    
    for(ll i = 0, j = l; i < r-l+1; i++, j++){
        arr[j] = b[i];
        // cout << b[i] << " ";
    }
    // cout << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    while(cin >> n && n){
        inv = 0;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        msort(0, (n-1));

        cout << inv << "\n";
    }
    return 0;
}