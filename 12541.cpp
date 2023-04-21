#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dt{
    string id; ll dd,mm,yy;

    dt(string _id, ll _dd, ll _mm, ll _yy){
        id = _id;
        dd = _dd;
        mm = _mm;
        yy = _yy;
    }
};

bool comp(dt a, dt b){
    if(a.yy!=b.yy) return a.yy > b.yy;
    if(a.mm!=b.mm) return a.mm > b.mm;
    if(a.dd!=b.dd) return a.dd > b.dd;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    vector<dt> hi;

    for(ll i = 0; i < n; i++){
        string id; ll dd, mm, yy;
        cin >> id >> dd >> mm >> yy;

        hi.emplace_back(id,dd,mm,yy);
    }

    sort(hi.begin(), hi.end(), comp);

    // for(auto &[id, dd, mm, yy]: hi){
    //     cout << id << " " << dd << " " << mm << " " << yy << "\n";
    // }
    cout << hi[0].id << "\n";
    cout << hi[hi.size()-1].id << "\n";

    return 0;
}