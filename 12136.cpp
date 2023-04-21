#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct schedule{
    ll h,m;
};

ll total(schedule hi){
    return (hi.h*60 + hi.m);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t; ll cs = 0;
    while(t--){
        cout << "Case " << ++cs << ": ";
        schedule x,y,xe,ye; char spt;
        cin >> x.h >> spt >> x.m;
        cin >> xe.h >> spt >> xe.m;
        cin >> y.h >> spt >> y.m;
        cin >> ye.h >> spt >> ye.m;

        if(total(y) < total(x)){
            swap(x,y);
            swap(xe,ye);
        }

        // cout << x.h << ":" << x.m << "\n";
        // cout << xe.h << ":" << xe.m << "\n";
        // cout << y.h << ":" << y.m << "\n";
        // cout << ye.h << ":" << ye.m << "\n";
        if(total(x) > total(xe)){
            xe.h += 24;
        }

        if(total(y) > total(ye)){
            ye.h += 24;
        }

        // cout << x.h << ":" << x.m << "\n";
        // cout << xe.h << ":" << xe.m << "\n";
        // cout << y.h << ":" << y.m << "\n";
        // cout << ye.h << ":" << ye.m << "\n";
        // bool overlap1 = total(xe) >= total(y);
        // bool overlap2 = (total(ye) <= total(xe)) && (total(y) >= total(x));

        // y dikepit x xe
        bool pos1 = (total(y) >= total(x)); // 23 y 00 
        bool pos2 = (total(y) <= total(xe)%1440); // 00 y end
        bool pos11 = (total(ye) >= total(x)); // 23 ye 00 
        bool pos22 = (total(ye) <= total(xe)%1440); // 00 ye end

        bool pos3 = (total(x) >= total(y)); // 23 x 00 
        bool pos4 = (total(x) <= total(ye)%1440); // 00 x end
        bool pos33 = (total(xe) >= total(y)); // 23 xe 00 
        bool pos44 = (total(xe) <= total(ye)%1440); // 00 xe end
        bool pos5 = (total(y) >= total(x)) && (total(xe) >= total(y)); // x y xe
        bool pos6 = (total(x) >= total(y)) && (total(ye) >= total(x)); // y x ye
        bool pasti = xe.h < 24 && ye.h < 24;
        
        if(xe.h>=24 && (pos1||pos2||pos11||pos22)){ // want to catch y ye
            cout << "Mrs Meeting\n";
        }

        else if(ye.h>=24&&(pos3||pos4||pos33||pos44)){
            cout << "Mrs Meeting\n";
        }

        else if(pasti && (pos5||pos6)) cout << "Mrs Meeting\n";

        else cout << "Hits Meeting\n";




    }
    return 0;
}