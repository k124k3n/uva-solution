#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll straight = 0, itn = 0, bab = 0, mat = 0, dd = 0;

ll check(char a){
    if(a == 'K') return 12;
    else if(a == 'Q') return 11;
    else if(a == 'J') return 10;
    else if(a == 'T') return 9;
    else if(a == 'A') return 0;
    else return (a - '0' - 1);
}

void solve(vector<string>& cards){
    unordered_multiset<ll> temp,real;
    for(auto x: cards){
        temp.insert(check(x[0]));
        real.insert(check(x[0]));
        // cout << check(x[0]) << " "; // debug

    }
    
    // cout << "\n"; // debug

    for(auto x: real){ // check straight
        bool strCond = true;
        vector<ll> tampung;
        ll list[4] = {x+1, x+2, x+3, x+4};

        for(auto j: list){
            if(temp.find(j%13) == temp.end()){
                strCond = false;
                break;
            }
        }

        if(strCond){
            ++straight; 
            // cout << "Its straight!\n"; // debug
            return;
        }
    }

    for(auto x: real){ // check ITN run of 4
        bool itnCond = true;

        ll list[3] = {x+1, x+2, x+3};
        for(auto j: list){
            if(temp.find(j%13) == temp.end()){
                itnCond = false;
                break;
            }
        }
        if(itnCond){
            ++itn; 
            // cout << "Its ITN!\n"; // debug
            return;
        }
    }

    
    for(auto x: real){ // check BAB run of (3+2)
        vector<ll> tampung;
        tampung.push_back(x);
        ll pick3[2] = {x+1, x+2};
        temp.erase(temp.find(x));

        // for(auto y: temp) cout << y << " ";
        // cout << "  After erasing\n";
        bool canPick3 = true;

        for(auto j: pick3){
            if(temp.find(j%13) == temp.end()){
                canPick3 = false;
            }
        }

        if(!canPick3){
            temp.insert(x);
            continue;
        }

        for(auto j: pick3){ // delete pick3
            tampung.push_back(j%13); // tampung
            temp.erase(temp.find(j%13));
            
        }


        // for(auto y: temp) cout << y << " ";
        // cout << "  After erasing pick3\n";
        bool canPick2 = false;

        for(auto j: temp){
            if(temp.find((j+1)%13) != temp.end()){
                canPick2 = true;
                break;
            }
        }

        for(auto j: tampung) temp.insert(j);
        // for(auto y: temp) cout << y << " ";
        // cout << "  After back to normal\n";
        if(!canPick2) continue;

        ++bab; 
        cout << "Its BAB!\n"; // debug
        return;
        
    }

    for(auto x: real){ // check MAT run of 3
        bool matCond = true;

        ll list[2] = {x+1, x+2};

        for(auto j: list){
            if(temp.find(j%13) == temp.end()){
                matCond = false;
                break;
            }
        }

        if(!matCond) continue;

        ++mat; 
        // cout << "Its MAT!\n"; // debug
        return;
        
    }

    for(auto x: real){ // check DD (2+2)
        vector<ll> tampung;
        tampung.push_back(x);
        ll pick2[2] = {x+1};
        temp.erase(temp.find(x));


        if(temp.find((x+1)%13) == temp.end()){
            temp.insert(x);
            continue;
        }

    
        tampung.push_back((x+1)%13);
        temp.erase(temp.find((x+1)%13));

        bool canPick2_2 = false;

        for(auto j: temp){
            if(temp.find((j+1)%13) != temp.end()){
                canPick2_2 = true;
                break;
            }
        }

        for(auto j: tampung) temp.insert(j);

        if(!canPick2_2) continue;

        ++dd;
        cout << "Its DD!\n"; // debug
        return;
    }
    
}

void addNew(vector<string>& newCard, map<string, bool> ada){
    string val[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
    string suit[4] = {"S", "H", "D", "C"};
    string temp = "";
    for(auto x: val){
        for(auto y: suit){
            temp = x + y;
            if(ada.find(temp) == ada.end()) newCard.push_back(temp);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    while(getline(cin,str) && str != "#"){
        map<string, bool> ada;
        ll initial = 0; straight = 0, itn = 0, bab = 0, mat = 0, dd = 0;
        ll change[5] = {0}; vector<string> card, newCard;

        istringstream ss(str); string temp;
        while(ss >> temp){
            card.push_back(temp);
            ada[temp] = true;
        }

        addNew(newCard, ada); solve(card);

        if(straight) initial = 99*47;
        else if(itn) initial = 9*47;
        else if(bab) initial = 4*47; 
        else if(mat) initial = 2*47;
        else if(dd) initial = 0;
        else initial = -47;

        // cout << initial << "\n";

        for(ll i = 0; i < 5; i++){
            straight = 0, itn = 0, bab = 0, mat = 0, dd = 0;
            string realCard = card[i];

            ll cuan = 0;
            for(auto x: newCard){
            
                card[i] = x;
                // for(auto x: card) cout << x << " ";
                // cout << " Sample\n";
                solve(card);
            }
            cuan += straight*100; cuan += itn*10;
            cuan += bab*5; cuan += mat*3; cuan += dd;
            cout << "If card " << i+1 << " changed\n"; 
            cout << "Straight chance: "  << straight << "\n";
            cout << "Invite-The-Neighbour chance: "  << itn << "\n";
            cout << "Bed-And-Breakfast chance: "  << bab << "\n";
            cout << "Manage-A-Trois chance: "  << mat << "\n";
            cout << "Double Dutch chance: "  << dd << "\n";
            cout << "cuan jika kartu " << i+1 << " diganti: " << cuan-94 << "\n";
            change[i] = cuan-94;
            card[i] = realCard;
        }

        ll Max = initial, maxi = -1;

        for(ll i = 0; i < 5; i++){
            if(change[i] > Max){
                Max = change[i];
                maxi = i;
            }
        }

        if(maxi != -1){
            cout << "Exchange " << card[maxi] << "\n";
        }
        else cout << "Stay\n";

    }
    return 0;
}