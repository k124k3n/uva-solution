#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << 1 << "\n";
    srand(time(0));
    ll mod = 10;
    ll m = rand() % mod;
    cout << m << "\n";
    ll total = 0;
    for(ll i = 0; i < m; i++){
        ll n = rand() % 4+1;
        ll leng = rand()%6+1;
        cout << n << "\n";
        string str;
        for(ll j = 0; j < leng; j++){
            ll num = rand()%2;
            str += (num + '0');
        }
        total += leng*n;
        cout << str << "\n";
    }

    char hm[4] = {'F', 'E', 'I', 'S'};

    ll q = rand() % 100;
    cout << q << "\n";

    for(ll i = 0; i < q; i++){
        ll word = rand()%4;
        if(word==3){
            cout << 'S' << " " << 0 << " " << total-1 << "\n";
            continue;
        }
        cout << hm[word] << " ";
        ll a = rand()%total;
        ll b = rand()%(total-a)+a;
        cout << a << " " << b << "\n";
    }
    return 0;
}