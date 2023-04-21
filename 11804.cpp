#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dt{
    string name; ll atk, def;
    dt(string _name, ll _atk, ll _def){
        name = _name;
        atk = _atk;
        def = _def;
    }

    friend bool operator<(dt a, dt b){
        return a.name < b.name;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    ll cs = 0;
    while(t--){
        cout << "Case " << ++cs << ":\n";
        vector<dt> hi;
        string li[5], lid[5];
        ll MaxAtk = LLONG_MIN;
        ll MaxDef = LLONG_MIN;

        for(ll i = 0; i < 10; i++){
            string name; ll atk, def; cin >> name >> atk >> def;
            hi.emplace_back(name, atk, def);
        }

        for(ll i = 0; i < 6; i++){
            for(ll j = i+1; j < 7; j++){
                for(ll k = j+1; k < 8; k++){
                    for(ll l = k+1; l < 9; l++){
                        for(ll m = l+1; m < 10; m++){
                            ll sum_atk = hi[i].atk + hi[j].atk + hi[k].atk + hi[l].atk + hi[m].atk;
                            ll sum_def = 0;
                            vector<ll> st = {i,j,k,l,m};
                            vector<ll> stdd;

                            for(ll x = 0; x < 10; x++){
                                if(x!=i&&x!=j&&x!=k&&x!=l&&x!=m) stdd.push_back(x);
                            }
                            
                            for(ll x = 0; x < 5; x++){
                                sum_def += hi[stdd[x]].def;
                            }

                            if(sum_atk > MaxAtk){
                                MaxAtk = sum_atk;
                                MaxDef = sum_def;
                                for(ll x = 0; x < 5; x++){
                                    li[x] = hi[st[x]].name;
                                }

                                for(ll x = 0; x < 5; x++){
                                    lid[x] = hi[stdd[x]].name;
                                }
                            }

                            else if(sum_atk == MaxAtk){
                                if(sum_def > MaxDef){
                                    MaxDef = sum_def;
                                    for(ll x = 0; x < 5; x++){
                                        li[x] = hi[st[x]].name;
                                    }

                                    for(ll x = 0; x < 5; x++){
                                        lid[x] = hi[stdd[x]].name;
                                    }
                                }

                                else if(sum_def == MaxDef){
                                    bool yes = false;
                                    for(ll x = 0; x < 5; x++){
                                        if(hi[st[x]].name < li[x]){
                                            for(ll x = 0; x < 5; x++){
                                                li[x] = hi[st[x]].name;
                                            }
                                            for(ll x = 0; x < 5; x++){
                                                lid[x] = hi[stdd[x]].name;
                                            }
                                            break;
                                        }
                                    }
                                }
                            }


                            sort(li, li+5);
                            sort(lid, lid+5);
                        }
                    }
                }
            }
        }

        cout << "(";
        for(ll i = 0; i < 5; i++){
            cout << li[i];
            if(i!=4) cout << ", ";
        }

        cout << ")\n";

        cout << "(";
        for(ll i = 0; i < 5; i++){
            cout << lid[i];
            if(i!=4) cout << ", ";
        }

        cout << ")\n";
    }
    return 0;
}