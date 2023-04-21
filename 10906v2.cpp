#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool checkt(string a){
    for(ll i = 0; a[i]; i++){
        if(a[i]=='+') return false;
    }
    return true;
}

// Goal: buat struktur dimana urutan operasi tetap sama dengan kurung terminimum yang mungkin
/*
    Observation:
        Jika variabel itu adalah operand pertama dalam ekspresi (operator yang mengapit hanya sebelah kanan),
            Jika operasi setelahnya +, maka kurung tidak akan berpengaruh. Lepas kurung.
            Jika operasi setelahnya *,
                Jika seluruh operasi dalam variabel adalah "*", urutan tidak berpengaruh.
                Else, pasang kurung

        Jika variabel itu ditengah-tengah (ada dua operator yang mengapit di kiri dan kanan) (IN CONSTRUCTION)
            Open kurung jika seluruh operasi dalam variabel adalah kali DAN dua operator kiri kanan adalah tambah
            Else, tutup kurung

        Jika variabel itu adalah operand terakhir dalam ekspresi (operator yang mengapit hanya sebelah kiri),
            Tutup kurung (jika operasi kiri adalah "+", atau TIDAK SEMUA operasi di variabel adalah "*")
            Else tutup kurung

    checkt harusnya cek dokumen original,
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    for(ll i = 1; i <= t; i++){

        cout << "Expression #" << i << ": ";
        map<string, string> hi, ori;

        ll n; cin >> n;
        cin.ignore(1000, '\n');
        string last;
        for(ll i = 0; i < n; i++){
            
            string str; getline(cin, str);
            if(str == ""){
                i--;
                continue;
            }
            ll eq = str.find("=");
            
            // extract var name
            string var = str.substr(0, eq);
            vector<string> op;

            var.pop_back();           
            last = var;
            string right = str.substr(eq+1);
            ori[var] = right;
            stringstream ss(right); string temp;
            string res;

            
            while(ss >> temp){
                op.push_back(temp);
            }

            
            for(ll i = 0; i < op.size(); i++){
                if(isalpha(op[i][0])){ // in construction

                    if(i==0){
                        if(op[i+1]=="+" || checkt(ori[op[i]])){ // case di depan ada + or semuanya kali, buka semua
                            res += hi[op[i]];
                            continue;
                        }

                        res += "(" + hi[op[i]] + ")";
                    }


                    else if(i == op.size()-1){
                        if((!checkt(ori[op[i]]) || (op.size()>=2 && op[i-1] == "*"))) res += "(" + hi[op[i]] + ")";
                        else res += hi[op[i]];
                    }

                    else if(checkt(ori[op[i]]) && op[i-1]=="+") res += hi[op[i]];

                    else res += "(" + hi[op[i]] + ")";
                    continue;
                }

                res += op[i];

                
            }

            

            hi[var] = res;

            // cout << var << " = " << hi[var] << "\n";
            
        }

        

        cout << hi[last] << "\n";
    }


    return 0;
}