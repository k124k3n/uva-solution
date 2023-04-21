#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[200000];
ll b[200000]; // hold temporary sorted element
ll inv = 0;

void msort(ll l, ll r){
    if(l >= r) return;
    ll mid = (l+r)/2;
    msort(l, mid); // recursive D&C
    msort(mid+1, r);

    ll litr = l, ritr = mid+1, bitr = 0;

    while(litr <= mid && ritr <= r){
        if(arr[litr] <= arr[ritr]){
            b[bitr++] = arr[litr++];
        }

        else{
            b[bitr++] = arr[ritr++];
            // inv += (mid-litr+1); // inv += byknya elemen yg tersisa di kiri
            // remove above to use inv_index
        }
    }

    while(litr <= mid) b[bitr++] = arr[litr++]; // sisa dari kiri
    while(ritr <= r) b[bitr++] = arr[ritr++]; // sisa dari kanan

    for(ll i = 0, j = l; i < (r-l+1); i++, j++){ // apply b to arr
        arr[j] = b[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n; 
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    msort(0, (n-1));
    for(ll i = 0; i < n; i++) cout << arr[i] << " ";
    cout << '\n';


    return 0;
}
