#include <bits/stdc++.h>
using namespace std;

#define ll long long

unordered_map<char, ll> e({
    {'B', 1}, {'U', 10}, {'S', 100}, {'P', 1000}, {'F', 10000}, {'T', 100000}, {'M', 1000000},
});

bool comp(char a, char b){
    return (e[a] > e[b]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    while(n--){
        unordered_map<char, ll> freq;
        bool valid = true;
        ll res = 0;
        string str; cin >> str;
        string srt = str; 
        sort(srt.begin(), srt.end(), comp);
        string r_srt = srt; reverse(r_srt.begin(), r_srt.end());

        for(ll i = 0; str[i]; i++){
            res += e[str[i]];
            ++freq[str[i]];
            if(freq[str[i]] > 9){
                valid = false;
            }
        }

        if(!valid || (str!=srt&&str!=r_srt)) cout << "error\n";
        else cout << res << "\n";
    }
    return 0;
}