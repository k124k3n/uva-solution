#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dt{
    ll d,m,y,p;
};

bool comp(dt a, dt b){
    if(a.y != b.y) return a.y < b.y;
    else if(a.m != b.m) return a.m < b.m;
    else return a.d < b.d;
}

ll daysin(ll m, ll y){
    ll diy[12] = {31,30,31,30,31,30,31,31,30,31,30,31};
    bool leapYear = (y%400==0) || (y%4==0 && y%100!=0);

    if(m==2){
        return 28 + leapYear;
    }

    else return diy[m-1];

    
}
bool check(dt a, dt b){
    ll diy[12] = {31,30,31,30,31,30,31,31,30,31,30,31};

    if(a.m==b.m) return ((a.d-b.d)==1);
    else if((a.m-b.m) == 1 && a.d==1){
        return(b.d==daysin(b.m,b.y));
    }

    else return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    while(cin >> n && n){
        dt arr[n];
        ll sum = 0, cnt=0;
        for(ll i = 0; i < n; i++){
            cin >> arr[i].d >> arr[i].m >> arr[i].y >> arr[i].p;
        }

        sort(arr,arr+n,comp);
        for(ll i = 0; i < n; i++){
            cout << arr[i].d << " " << arr[i].m << " " << arr[i].y << " " << arr[i].p << "\n";
        } cout << "\n\n";

        for(ll i = 1; i < n; i++){
            bool cond = arr[i].d == 1 && arr[i].m==1;
            bool cond2 = arr[i-1].d == 31 && arr[i-1].m==12;
            if(arr[i].y==(arr[i-1].y+1) && cond && cond2){
                sum += arr[i].p - arr[i-1].p;
                ++cnt;
            }
            else if(arr[i].y == arr[i-1].y && check(arr[i], arr[i-1])){
                sum += arr[i].p - arr[i-1].p;
                ++cnt;
            }
        }
        
        cout << cnt << " " << sum << "\n";
    }
    return 0;
}