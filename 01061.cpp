#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<string, ll> prio; map<char, ll> typ_prio;

bool comp(string a, string b){
    char typA = a[a.length()-1]; char typB = b[b.length()-1];
    a.pop_back(), b.pop_back();

    if(a == b) return typ_prio[typA] > typ_prio[typB];
    return prio[a] < prio[b];

    
}

/*
AA A
AB AB
AO A
BB B
BO B
OO O
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    prio["O"] = 0; prio["AB"] = 1; prio["B"] = 2 ;prio["A"] = 3;
    typ_prio['+'] = 0, typ_prio['-'] = 1;

    map<string, string> blood; map<string, vector<string>> brute;
    blood["AA"] = "A"; blood["AB"] = "AB"; blood["AO"] = "A"; blood["BB"] = "B"; blood["BO"] = "B"; blood["OO"] = "O";
    brute["A"].push_back("AO"); brute["A"].push_back("AA"); brute["AB"].push_back("AB"); brute["B"].push_back("BB"); brute["B"].push_back("BO"); brute["O"].push_back("OO");
    vector<string> allB;
    allB.push_back("AA"), allB.push_back("AO"), allB.push_back("AB"), allB.push_back("BB"), allB.push_back("BO"),  allB.push_back("OO");
    char allRh[2] = {'-', '+'};



    string str; ll cs = 1;
    while(getline(cin, str)){
        if(str == "") continue;
        
        istringstream ss(str); string temp;
        vector<string> fams; bool everSwap = false;

        while(ss >> temp) fams.push_back(temp);

        if(fams[0] == "E" && fams[1] == "N" && fams[2] == "D") break;

        cout << "Case " << cs++ << ": "; 

        if(fams[1][0] == '?'){
            swap(fams[1], fams[0]);
            everSwap = true;
        }

        if(fams[0][0] == '?'){
            multiset<char> rh; set<string> res;
            rh.insert(fams[1][fams[1].length()-1]);
            string realOne = fams[1];
            fams[1].pop_back();
            char initRh = fams[2][fams[2].length()-1];
            string correct = fams[2];
            correct.pop_back();
            for(auto bloodA: allB){
                for(auto tempRh: allRh){
                    rh.insert(tempRh);
                    for(auto bloodB: brute[fams[1]]){
                        string temp;
                        for(auto x: bloodA){
                            for(auto y: bloodB){ // brute every char of bloodA and bloodB
                                // temp = string(1,x) + string(1,y);
                                // sort(temp.begin(), temp.end());
                                temp = string(1,x)+string(1,y);
                                sort(temp.begin(), temp.begin()+2);
                                
                                // cout << temp << "\n";
                                if(blood[temp] == correct){
                                    if(rh.find('+') != rh.end()) res.insert(blood[bloodA] + string(1,tempRh));
                                    else if(initRh == '-') res.insert(blood[bloodA] + string(1,tempRh));
                                }

                            }
                        }
                    }
                    rh.erase(rh.find(tempRh));
                }
            }

            string final = "{";
            vector<string> hii;

            for(auto x: res) hii.push_back(x);

            sort(hii.begin(), hii.end(), comp);
            
            for(auto x: hii) final += x + ", ";

            if(res.size() != 0){
                final.pop_back();
                final.pop_back();
            }

            final += "}";

            if(everSwap){
                cout << realOne << " ";
                if(res.size() == 0) cout << "IMPOSSIBLE ";
                else if (res.size() == 1) cout << *res.begin() << " ";
                else cout << final << " ";
                cout << fams[2] << "\n";
            }
            else{
                if(res.size() == 0) cout << "IMPOSSIBLE ";
                else if (res.size() == 1) cout << *res.begin() << " ";
                else cout << final << " ";

                cout << realOne << " ";
                cout << fams[2] << "\n";
            }
        }

        else if(fams[2][0] == '?'){
            multiset<char> rh; set<string> res;
            string realOne = fams[0], realTwo = fams[1];
            rh.insert(fams[1][fams[1].length()-1]);
            rh.insert(fams[0][fams[0].length()-1]);
            
            fams[1].pop_back(); fams[0].pop_back();
            // cout << brute[fams[0]][0] << " " << brute[fams[1]][0] << "\n";
            for(auto bloodA: brute[fams[0]]){
                for(auto tempRh: allRh){
                    for(auto bloodB: brute[fams[1]]){
                        string temp;
                        for(auto x: bloodA){
                            for(auto y: bloodB){ // brute every char of bloodA and bloodB
                                temp = string(1,x)+string(1,y);
                                sort(temp.begin(), temp.begin()+2);
                                
                                if(rh.find('+') != rh.end() || tempRh == '-') res.insert(blood[temp] + string(1,tempRh));
                            }
                        }
                    }
                }
            }

            string final = "{";
            vector<string> hii;

            for(auto x: res) hii.push_back(x);

            sort(hii.begin(), hii.end(), comp);
            
            for(auto x: hii) final += x + ", ";
            if(res.size() != 0){
                final.pop_back();
                final.pop_back();
            }
            final += "}";
            cout << realOne << " ";
            cout << realTwo << " ";

            if(res.size() == 0) cout << "IMPOSSIBLE\n";
            else if (res.size() == 1) cout << *res.begin() << "\n";
            else cout << final << "\n";
        }

        else{
            for(ll i = 0; i < fams.size(); i++){
                cout << fams[i];

                if(i != fams.size()-1) cout << " ";
            }
            cout << "\n";
        }
    }

    
    return 0;
}