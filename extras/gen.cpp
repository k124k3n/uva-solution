#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    registerGen(argc, argv, 1);

    // int a = opt<int>("a");
    // int b = opt<int>("b");
    
    int a = rnd.next(1, 1'000'000'000);
    int b = rnd.next(1, 1'000'000'000);

    cout << a << " " << b << "\n";

    return 0;
}