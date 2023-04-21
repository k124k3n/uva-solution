#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll hh,mm; char sprtor;
    while(cin >> hh >> sprtor >> mm){
        if(hh==0&&mm==0) break;
        double mprog = mm*6;
        double hprog = hh*30*12 + mprog;
        double Max = max(mprog, (double)hprog/12);
        double Min = min(mprog, (double)hprog/12);
        double res = min(Max-Min, 360-(Max-Min));
        cout << fixed << setprecision(3) << res << "\n";

    }
    return 0;
}