#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ost tree;

    for(int i = 1; i <= 2000000; i += 2) tree.insert(i);

    for(int i = 1; i < tree.size(); i++){
        int bil = *tree.find_by_order(i);
        if(bil > tree.size()) break;
        for(int j = bil-1; j < tree.size(); j += bil-1){
            tree.erase(*tree.find_by_order(j));
        }        

    }

    int li[tree.size()];

    unordered_map<int, bool> ex;

    int k = 0;

    for(auto x: tree){
        li[k++] = x;
        ex[x] = true;
    }


    int n;

    
    while(cin >> n){
        if(n%2!=0){
            cout << n << " is not the sum of two luckies!\n";
            continue;
        }
        int lb = upper_bound(li, li + tree.size(), n/2) - li - 1;

        bool found = false;

        for(int i = lb; i >= 0; i--){
            if(ex[n - li[i]]){
                cout << n << " is the sum of " << li[i] << " and " << n - li[i] << ".\n";
                found = true;
                break;
            }
        }

        if(!found) cout << n << " is not the sum of two luckies!\n";
    }



    return 0;
}