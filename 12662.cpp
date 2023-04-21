#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    cin.ignore(1000, '\n');
    vector<string> arr;
    vector<ll> pos;
    unordered_map<ll, string> w;
    string str, l[n+1], r[n+1]; getline(cin, str);
    stringstream ss(str); string temp;

    while(ss >> temp){
        arr.push_back(temp);
        if(isalpha(temp[0])){
            pos.push_back(arr.size()-1);
            w[arr.size()-1] = temp;
        }
    }


    ll k; cin >> k;

    for(ll i = 0; i < k; i++){
        ll temp; cin >> temp;
        --temp;

        if(isalpha(arr[temp][0])) cout << arr[temp] << "\n";
        else{
            ll lb = lower_bound(pos.begin(), pos.end(), temp) - pos.begin();
            
            if(lb == 0){
                for(ll j = 0; j < pos[lb]-temp; j++){
                    cout << "left of ";
                }

                cout << arr[pos[lb]] << "\n";
            }

            else if(lb >= pos.size()){
                for(ll j = 0; j < temp - *(pos.end()-1); j++){
                    cout << "right of ";
                }

                cout << arr[*(pos.end()-1)] << "\n";

            }

            else{
                ll kiri = temp - pos[lb-1], kanan = pos[lb] - temp;

                if(kiri == kanan){
                    cout << "middle of " << arr[pos[lb-1]] << " and " << arr[pos[lb]] << "\n";
                }

                else if(kiri < kanan){
                    for(ll j = 0; j < temp - pos[lb-1]; j++){
                        cout << "right of ";
                    }

                    cout << arr[pos[lb-1]] << "\n";
                }

                else{
                    for(ll j = 0; j < pos[lb] - temp; j++){
                        cout << "left of ";
                    }

                    cout << arr[pos[lb]] << "\n";
                }
            }
        }
    }
    return 0;
}