#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // : C, C#, D, D#, E, F, F#, G, G#, A, A#, B
    ll li[8] = {0,2,2,1,2,2,2,1};
    string arr[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

    set<string> C, Cm, D, Dm, E, F, Fm, G, Gm, A, Am, B;

    ll itr = 0;
    for(auto x: li){
        itr += x;
        C.insert(arr[itr%12]);
    }

    itr = 1;
    for(auto x: li){
        itr += x;
        Cm.insert(arr[itr%12]);
    }

    itr = 2;
    for(auto x: li){
        itr += x;
        D.insert(arr[itr%12]);
    }

    itr = 3;
    for(auto x: li){
        itr += x;
        Dm.insert(arr[itr%12]);
    }

    itr = 4;
    for(auto x: li){
        itr += x;
        E.insert(arr[itr%12]);
    }

    itr = 5;
    for(auto x: li){
        itr += x;
        F.insert(arr[itr%12]);
    }

    itr = 6;
    for(auto x: li){
        itr += x;
        Fm.insert(arr[itr%12]);
    }

    itr = 7;
    for(auto x: li){
        itr += x;
        G.insert(arr[itr%12]);
    }

    itr = 8;
    for(auto x: li){
        itr += x;
        Gm.insert(arr[itr%12]);
    }

    itr = 9;
    for(auto x: li){
        itr += x;
        A.insert(arr[itr%12]);
    }

    itr = 10;
    for(auto x: li){
        itr += x;
        Am.insert(arr[itr%12]);
    }

    itr = 11;
    for(auto x: li){
        itr += x;
        B.insert(arr[itr%12]);
    }
    string str;

    while(getline(cin, str) && str != "END"){
        istringstream ss(str);
        set<string> hi;
        string temp;
        while(ss >> temp){
            hi.insert(temp);
        }
        
        if(includes(C.begin(), C.end(), hi.begin(), hi.end())) cout << "C ";
        if(includes(Cm.begin(), Cm.end(), hi.begin(), hi.end())) cout << "C# ";
        if(includes(D.begin(), D.end(), hi.begin(), hi.end())) cout << "D ";
        if(includes(Dm.begin(), Dm.end(), hi.begin(), hi.end())) cout << "D# ";
        if(includes(E.begin(), E.end(), hi.begin(), hi.end())) cout << "E ";
        if(includes(F.begin(), F.end(), hi.begin(), hi.end())) cout << "F ";
        if(includes(Fm.begin(), Fm.end(), hi.begin(), hi.end())) cout << "F# ";
        if(includes(G.begin(), G.end(), hi.begin(), hi.end())) cout << "G ";
        if(includes(Gm.begin(), Gm.end(), hi.begin(), hi.end())) cout << "G# ";
        if(includes(A.begin(), A.end(), hi.begin(), hi.end())) cout << "A ";
        if(includes(Am.begin(), Am.end(), hi.begin(), hi.end())) cout << "A# ";
        if(includes(B.begin(), B.end(), hi.begin(), hi.end())) cout << "B ";
        cout << "\n";
    }

    return 0;
}