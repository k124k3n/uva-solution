#include <bits/stdc++.h>
using namespace std;

#define ll long long

class BigInt{
    private:
        vector<ll> a;

    public:
        BigInt(vector<ll> &x){
            a = x;
        }

        // friend string operator+(vector<ll> &b){
        //     if(b.size() > a.size()) swap(a, b);

        //     for(ll i = b.size()-1; b[i] != 0 && i > 0; i--){
        //         a[i] += b[i];

        //         if(a[i] > 9){
        //             ++a[i-1];
        //             a[i] %= 10;
        //         }
        //     }

        // }

        void plus(vector<ll> &b){
            if(b.size() > a.size()) swap(a, b);

            for(ll i = a.size()-1; i >= 0; i--){
                // cout << a[i] << " + " << b[i] << " = " << a[i] + b[i] << "\n";
                a[i] += b[i];
                
                if(a[i] > 9){
                    ++a[i-1];
                    a[i] %= 10;
                }
            }

            while(a.size() > 1 && a.back()==0){
                a.pop_back();
            }

            ll j = 0;

            while(a[j]==0 && j < a.size()) ++j;

            for(ll i = a.size()-1; i >= j; i--){
                cout << a[i];
            }

            cout << "\n";
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    while(n--){
        string a,b; cin >> a >> b;
        vector<ll> x, y;
        

        while(a.back()=='0') a.pop_back();
        while(b.back()=='0') b.pop_back();

        a += "0"; b += "0";

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        // cout << a << " " << b << "\n";
        if(b.length() > a.length()) swap(a, b);

        
        for(ll i = 0; i < a.length(); i++){
            x.push_back(a[i] - '0');
        }


        for(ll i = 0; i < a.length()-b.length(); i++){
            y.push_back(0);
        }

        for(ll i = 0; i < b.length(); i++){
            y.push_back(b[i] - '0');
        }

        BigInt hi(x);

        hi.plus(y);
    }
    return 0;
}
