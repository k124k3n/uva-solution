#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str; getline(cin, str);

    vector<string> res; ll cs = 0;
    unordered_set<string> un;
    unordered_set<string> f;
    unordered_map<string,ll> freq;
    deque<string> hi;


    while(getline(cin, str)){

        ll L=0,R=0;
        // cout << str << "\n";
        

        if(str == "END"){
            
            hi.push_back(res[0]);
            ll l = 0, r = 0;
            
            f.insert(res[0]);
            ++freq[res[0]];
            
            ll Min = LLONG_MAX;

            for(ll i = 1; i < res.size(); i++){
                ++freq[res[i]];
                while(freq[hi[0]] > 1){
                    --freq[hi[0]];
                    hi.pop_front();
                    l++;
                    
                }
                    
                hi.push_back(res[i]);
                f.insert(res[i]);
                
                r = i;

                // cout << cs << " " << l << " " << r << "\n";
                // cout << cs << " " << L << " " << R << "\n";
                if(f.size()==un.size()){
                    
                    if((r-l+1) < Min){
                        L = l, R = r;
                        Min = r-l+1;
                    }
                }

            }

            cout << "Document " << ++cs << ": " << L+1 << " " << R+1 << "\n";
            res.clear();
            un.clear();
            f.clear();
            hi.clear();
            freq.clear();
            continue;
        }

        string temp;

        for(ll i = 0; i < str.length(); i++){
            // cout << str << "\n";
            if(isalpha(str[i])){
                while(i < str.length() && isalpha(str[i])){
                    temp += string(1, str[i]);
                    i++;
                }

                i--;
                un.insert(temp);
                res.push_back(temp);
                // cout << temp << "\n";
                temp = "";
                
            }
            
        }
        
    }
    return 0;
}