#include <bits/stdc++.h>
using namespace std;

#define ll long long

set<vector<ll>> brute, b1, b2, b3, b4, b5, b6;
ll cnt;

ll RtoA(string a){
    ll sum = 0;

    map<char, ll> conv({
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1},
    });

    for(ll i = 0; a[i]; i++){
        if(a[i+1] && conv[a[i]] < conv[a[i+1]]){
            sum += conv[a[i+1]] - conv[a[i]];
            i++;
        }

        else sum += conv[a[i]];
    }

    return sum;
}

void bf(string a, string b, string c, set<vector<ll>> li, set<char> ch){
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    // cout << (char) *(a.end()-1) << " " << (char) *(b.end()-1) << " " << (char)*(c.end()-1) << "\n";
    for(auto arr: li){ // bruteeeeeeee
        map<char, ll> dt;
        ll A = 0, B = 0, C = 0;
        ll k = 0;

        for(auto x: ch){
            dt[x] = arr[k];
            ++k;
        }

        
        if(dt[a.back()]==0||dt[b.back()]==0||dt[c.back()]==0) continue;


        ll st = 1;
        

        for(auto x: a){ // processing A
            A += dt[x]*st;
            st *= 10;
        }

        st = 1;
        for(auto x: b){ // processing B
            B += dt[x]*st;
            st *= 10;
        }

        st = 1;
        for(auto x: c){ // processing C
            C += dt[x]*st;
            st *= 10;
        }

        // cout << dt['I'] << " " << dt['X'] << " " << dt['L'] << " " << dt['V'] << "\n\n";    
        if((A+B)==C){
            
            ++cnt;
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    do{
        brute.insert({arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]});
    } while(next_permutation(arr, arr+10));

    for(auto x: brute){
        b1.insert({x[0]});
        b2.insert({x[0], x[1]});
        b3.insert({x[0], x[1], x[2]});
        b4.insert({x[0], x[1], x[2], x[3]});
        b5.insert({x[0], x[1], x[2], x[3], x[4]});
        b6.insert({x[0], x[1], x[2], x[3], x[4], x[5]});
    }


    string str;
    while(cin >> str && str != "#"){
        cnt=0;
        string a = str.substr(0, str.find("+"));
        string b = str.substr(str.find("+")+1, str.find("=") - str.find("+")-1);
        string c = str.substr(str.find("=")+1);

        if(RtoA(a) + RtoA(b) == RtoA(c)) cout << "Correct ";
        else cout << "Incorrect ";

        set<char> ch;
        for(auto x: a) ch.insert(x);
        for(auto x: b) ch.insert(x);
        for(auto x: c) ch.insert(x);
        if(ch.size()==1) bf(a, b, c, b1, ch);
        else if(ch.size()==2) bf(a, b, c, b2, ch);
        else if(ch.size()==3) bf(a, b, c, b3, ch);
        else if(ch.size()==4) bf(a, b, c, b4, ch);
        else if(ch.size()==5) bf(a, b, c, b5, ch);
        else if(ch.size()==6) bf(a, b, c, b6, ch);
        else bf(a, b, c, brute, ch);
            
        if(cnt > 1) cout << "ambiguous\n";
        else if(cnt == 1) cout << "valid\n";
        else cout << "impossible\n";
        
    }

    return 0;
}