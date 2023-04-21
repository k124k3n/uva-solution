#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool comp(string a, string b){
    for(ll i = 0; i < min(a.length(), b.length()); i++){
        if(a[i] != b[i]) return a[i] < b[i];
    }

    return a.length() < b.length();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;

    while(cin >> n && n){
        vector<string> hi;

        for(ll i = 0; i < n; i++){
            string temp; cin >> temp;
            hi.push_back(temp);
        }

        sort(hi.begin(), hi.end(), comp);

        string res;

        string p = hi[hi.size()/2], q = hi[hi.size()/2-1];

        for(ll i = 0; i < min(p.length(), q.length()); i++){
            if(p[i] != q[i]){
                if(i!=q.length()-1) res += q[i]+1;
                else res += q[i];
                break;
            }

            else res += p[i];
        }

        if(res!=p) cout << res << "\n";
        else{
            if(p.length()==q.length()) cout << q << "\n";
            else{
                res = q.substr(0, min(q.length(), p.length()));
                for(ll i = p.length(); i < q.length(); i++){
                    if(q[i] != 'Z'){
                        if(i!=q.length()-1)res += q[i]+1;
                        else res += q[i];
                        break;
                    }

                    else res += q[i];
                }

                cout << res << "\n";
            }
        }

        
    }
    return 0;
}