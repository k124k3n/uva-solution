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

void csort(multiset<ll> temp, vector<ll>& real){
    ll init = *temp.begin();
    while(temp.size() > 0){
        // for(auto x: temp) cout << x << " ";
        // cout << "hi\n";
        if(temp.lower_bound(init) != temp.end()){
            init = *temp.lower_bound(init);
            real.push_back(init);
            temp.erase(temp.lower_bound(init));
            ++init;
        }
        else init = *temp.begin();
    }
}

void solve(vector<string>& cards){
    multiset<ll> temp;
    for(auto x: cards){
        temp.insert(check(x[0]));
        cout << check(x[0]) << " "; // debug

    }
    
    cout << "\n"; // debug
    vector<ll> real; unordered_set<ll> hm;
    csort(temp, real);

    for(auto x: real){
        hm.insert(x);
        cout << x << " "; // debug
    } cout << "\n"; // debug

    for(ll i = 0; i < real.size(); i++){ // check straight
        bool strCond = ((real[i%5]+1)%13) == (real[(i+1)%5]%13) && ((real[(i+1)%5]+1)%13) == ((real[(i+2)%5])%13) && ((real[(i+2)%5]+1)%13) == ((real[(i+3)%5])%13) && ((real[(i+3)%5]+1)%13) == ((real[(i+4)%5])%13);
        if(strCond){
            ++straight; 
            cout << "Its straight!\n"; // debug
            return;
        }
    }

    for(auto x: hm){ // check ITN run of 4
        bool itnCond = (hm.find((x+1) % 13) != hm.end()) && (hm.find((x+2) % 13) != hm.end()) && (hm.find((x+3) % 13) != hm.end());
        if(itnCond){
            ++itn; 
            cout << "Its ITN!\n"; // debug
            return;
        }
    }

    for(ll i = 0; i < real.size(); i++){ // check BAB run of (3+2)

        bool run3 =  (((real[i%5]+1)%13) == (real[(i+1)%5]%13) && ((real[(i+1)%5]+1)%13) == ((real[(i+2)%5])%13))
                    || ( ((real[(i+1)%5]+1)%13) == ((real[(i+2)%5])%13) && ((real[(i+2)%5]+1)%13) == ((real[(i)%5])%13))
                    || ( ((real[(i+2)%5]+1)%13) == ((real[(i)%5])%13) && ((real[i%5]+1)%13) == ((real[(i+1)%5])%13));
        
        bool run2 =  (((real[(i+3)%5]+1)%13) == (real[(i+4)%5]%13))
                    || ( ((real[(i+4)%5]+1)%13) == (real[(i+3)%5]%13) );                    
                    
        if(run3 && run2){
            ++bab; 
            cout << "Its BAB!\n"; // debug
            return;
        }
    }
    
    for(auto x: hm){ // check MAT run of 3
        bool matCond = (hm.find((x+1) % 13) != hm.end()) && (hm.find((x+2) % 13) != hm.end());

        if(matCond){
            ++mat; 
            cout << "Its MAT!\n"; // debug
            return;
        }
    }

    for(ll i = 0; i < real.size(); i++){ // check DD (2+2)
        bool run2 =  (((real[i%5]+1)%13) == (real[(i+1)%5]%13))
                    || ( ((real[(i+1)%5]+1)%13) == (real[(i)%5]%13) );
        bool run2_1 = (((real[(i+2)%5]+1)%13) == (real[(i+3)%5]%13))
                    || ( ((real[(i+3)%5]+1)%13) == (real[(i+2)%5]%13) );
        
        bool run2_2 = (((real[(i+3)%5]+1)%13) == (real[(i+4)%5]%13))
                    || ( ((real[(i+4)%5]+1)%13) == (real[(i+3)%5]%13) );

        if(run2 && (run2_1 || run2_2)){
            ++dd;
            cout << "Its DD!\n"; // debug
            return;
        }
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