#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct board{
    string id; ll ps, penalty;

    board(string _id, ll _ps, ll _penalty){
        id = _id;
        ps = _ps;
        penalty = _penalty;
    }
};

bool comp(board a, board b){
    if(a.ps != b.ps) return a.ps > b.ps;
    else if(a.penalty != b.penalty) return a.penalty < b.penalty;
    else return stoi(a.id) < stoi(b.id);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    cin.ignore(100, '\n');
    string str;
    
    unordered_set<string> l;
    unordered_map<string, unordered_map<string, bool>> solved;
    unordered_map<string, unordered_map<string, ll>> st;
    unordered_map<string, vector<string>> solvedBy;
    vector<board> table;

    ll sp = 0;

    while(getline(cin, str)){
        stringstream ss(str);
        string temp;
        vector<string> s;
        while(ss >> temp){
            s.push_back(temp);
        }

        // cout << s.size() << "\n";
        if(s.size()!=0){
            string id = s[0];
            string prob = s[1];
            ll tm = stoi(s[2]);
            string v = s[3];
            l.insert(id);
            if(!solved[id][prob]){
                if(v == "I") st[id][prob] += 20;

                if(v == "C"){
                    st[id][prob] += tm;
                    solved[id][prob] = true;
                    solvedBy[id].push_back(prob);
                }
            }
        }

        if(s.size()==0){
            if(s.size()==0){
                ++sp;
                if(sp==1) continue;
            }
            for(auto x: l){ // filling table
                string id = x;
                ll ps = solvedBy[id].size();
                ll penalty = 0;

                for(auto prob: solvedBy[id]){
                    penalty += st[id][prob];
                    // cout << id << " " << prob << " " << st[id][prob] << "\n";
                }

                table.emplace_back(id, ps, penalty);
            }
            sort(table.begin(), table.end(), comp);

            for(auto &[id, ps, penalty]: table){
                cout << id << " " << ps << " " << penalty << "\n";
            }

            if(cin.good()) cout << "\n";
            
            l.clear();
            solvedBy.clear();
            solved.clear();
            st.clear();
            table.clear();
            continue;
        }

    }


    
    for(auto x: l){ // filling table
        string id = x;
        ll ps = solvedBy[id].size();
        ll penalty = 0;

        for(auto prob: solvedBy[id]){
            penalty += st[id][prob];
            // cout << id << " " << prob << " " << st[id][prob] << "\n";
        }

        table.emplace_back(id, ps, penalty);
    }
    sort(table.begin(), table.end(), comp);

    for(auto &[id, ps, penalty]: table){
        cout << id << " " << ps << " " << penalty << "\n";
    }

    if(cin.good()) cout << "\n";
    
    l.clear();
    solvedBy.clear();
    solved.clear();
    st.clear();
    table.clear();

    
    return 0;
}