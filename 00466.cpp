#include <bits/stdc++.h>
using namespace std;

#define ll long long

string a[20], b[20];

bool vref(ll n){
    bool same = true;
    string cp[n];
    for(ll i = 0; i < n; i++){
        cp[i] = a[i];
    }

    for(ll i = n-1, j = 0; i >= 0; i--, j++){
        a[j] = cp[i];

        if(a[j] != b[j]) same = false;
    }


    return same;
}

bool check90(ll n){
    for(ll i = n-1, k = 0; i >= 0; i--, k++){
        string hi;
        for(ll j = 0; j < n; j++){
            hi += string(1, b[j][i]);
        }
        
        
        if(hi != a[k]) return false;
    }

    return true;
}

bool check180(ll n){
    for(ll i = n-1, k = 0; i >= 0; i--, k++){
        string hi = a[i];
        reverse(hi.begin(), hi.end());

        if(hi != b[k]) return false;
    }

    return true;
}

bool check270(ll n){
    for(ll i = n-1, k = 0; i >= 0; i--, k++){
        string hi;
        for(ll j = 0; j < n; j++){
            hi += string(1, a[j][i]);
        }
        
        
        if(hi != b[k]) return false;
    }

    return true;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; ll cs = 0;

    while(cin >> n){
        cout << "Pattern " << ++cs << " was";
        cin.ignore(1000, '\n');
        bool same = true;
        
        for(ll i = 0; i < n; i++){
            string str; getline(cin, str);
            a[i] = str.substr(0, n);
            b[i] = str.substr(n+1);

            if(a[i]!=b[i]) same = false;
        }

        if(same) cout << " preserved.\n";
        else if(check90(n)) cout << " rotated 90 degrees.\n";
        else if(check180(n)) cout << " rotated 180 degrees.\n";
        else if(check270(n)) cout << " rotated 270 degrees.\n";
        else if(vref(n)) cout << " reflected vertically.\n";
        else if(check90(n)) cout << " reflected vertically and rotated 90 degrees.\n";
        else if(check180(n)) cout << " reflected vertically and rotated 180 degrees.\n";
        else if(check270(n)) cout << " reflected vertically and rotated 270 degrees.\n";
        else cout << " improperly transformed.\n";
        
    }
    return 0;
}