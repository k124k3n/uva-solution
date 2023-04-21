#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

double mandis(ll a, ll b, ll c, ll d){

    return((double)sqrt((double)abs(a-c)*abs(a-c) + (double)abs(b-d)*abs(b-d)));
}

double brute(string home, char a, map<char, pair<ll, ll>> loc){
    double Min = LLONG_MAX;
    // cout << home << " " << a << "   hi!\n";
    for(auto x: home){
        Min = min(Min, mandis(loc[x].f, loc[x].s, loc[a].f, loc[a].s));
        // cout << "x = " << x << "\n";
        // cout << "min = " << "mandis(" << loc[x].f  << ", " << loc[x].s << ",  " << loc[a].f << ",  " << loc[a].s << ")" << " = " << mandis(loc[x].f, loc[x].s, loc[a].f, loc[a].s) << "\n";
    }

    // cout << "Min = " << Min << "\n\n";
    // cout << "Jarak " << a << " = " << Min << "\n";
    return Min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << fixed << setprecision(2);
    // set<char> char_list, schar_list;
    map<char, pair<ll,ll>> qwerloc, dvorloc;

    char qwerty[4][14] = {
        {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', ' '}, 
        {' ', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\'},
        {' ', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', ' ', ' '},
        {' ', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', ' ', ' ', ' '}
    };

    char sqwerty[4][14] = {
        {'~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', ' '}, 
        {' ', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '{', '}', '|'},
        {' ', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ':', '"', ' ', ' '},
        {' ', 'z', 'x', 'c', 'v', 'b', 'n', 'm', '<', '>', '?', ' ', ' ', ' '}
    };

    char dvorak[4][14] = {
        {'`', '1', '2', '3', 'q', 'j', 'l', 'm', 'f', 'p', '/', '[', ']', ' '}, 
        {' ', '4', '5', '6', '.', 'o', 'r', 's', 'u', 'y', 'b', ';', '=', '\\'},
        {' ', '7', '8', '9', 'a', 'e', 'h', 't', 'd', 'c', 'k', '-', ' ', ' '},
        {' ', '0', 'z', 'x', ',', 'i', 'n', 'v', 'w', 'g', '\'', ' ', ' ', ' '}
    };

    char sdvorak[4][14] = {
        {'~', '!', '@', '#', 'q', 'j', 'l', 'm', 'f', 'p', '?', '{', '}', ' '}, 
        {' ', '$', '%', '^', '>', 'o', 'r', 's', 'u', 'y', 'b', ':', '+', '|'},
        {' ', '&', '*', '(', 'a', 'e', 'h', 't', 'd', 'c', 'k', '_', ' ', ' '},
        {' ', ')', 'z', 'x', '<', 'i', 'n', 'v', 'w', 'g', '"', ' ', ' ', ' '}
    };

    for(ll i = 0; i < 4; i++){
        for(ll j = 0; j < 14; j++){
            if(qwerty[i][j] != ' '){
                qwerloc[sqwerty[i][j]] = make_pair(i, j);
                qwerloc[qwerty[i][j]] = make_pair(i, j);
            }

            if(dvorak[i][j] != ' '){
                dvorloc[dvorak[i][j]] = make_pair(i, j);
                dvorloc[sdvorak[i][j]] = make_pair(i, j);
            }
        }
    }

    string homeqwertlr = "asdfjkl;";
    string homeqwert1 = "fghj";
    string homedvor = "ehtd";
    string str;
    while(getline(cin, str)){
        // if(str == "") continue;
        double dvor=0,qwertylr=0, qwerty1 = 0;
        for(ll i = 0; i < str.length(); i++){
            if(str[i] == ' ') continue;
            if(isalpha(str[i])) str[i] = tolower(str[i]);
            qwertylr += (double) 2 * brute(homeqwertlr, str[i], qwerloc);
            qwerty1 += (double) 2 * brute(homeqwert1, str[i], qwerloc);
            dvor += (double) 2 * brute(homedvor, str[i], dvorloc);
        }

        cout << qwertylr << " " << qwerty1 << " " << dvor << "\n";
    }
    return 0;
}