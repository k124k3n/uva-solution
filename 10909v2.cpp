#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, splay_tree_tag, tree_order_statistics_node_update> ost;

bool ex[2000500];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ost tree;

    for(int i = 1; i <= 2000000; i += 2) tree.insert(i);

    for(auto i = ++tree.begin(); i != tree.end(); i++){
        int bil = *i;
        if(bil > tree.size()) break;
        for(int j = bil-1; j < tree.size(); j += bil-1){
            tree.erase(*tree.find_by_order(j));
        }        

    }


    int k = 0;

    for(auto x: tree){
        ex[x] = true;
    }


    int n;

    
    while(cin >> n){
        if(n%2!=0){
            cout << n << " is not the sum of two luckies!\n";
            continue;
        }

        bool found = false;

        for(int i = n/2; i >= 1; i--){
            if(ex[n - i] && ex[i]){
                cout << n << " is the sum of " << i << " and " << n - i << ".\n";
                found = true;
                break;
            }
        }

        if(!found) cout << n << " is not the sum of two luckies!\n";
    }



    return 0;
}