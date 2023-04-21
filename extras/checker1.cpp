#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]){
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    
    int n = inf.readDouble(0, 1'000'000, "participant");

    for(int i = 0; i < n; i++){
        int Ai = ouf.readDouble(0, 1'000'000'000, "participant");
        int jAi = ans.readDouble(0, 1'000'000'000, "participant");
        if(Ai!=jAi) quitf(_wa, "wrong answer");
        ouf.readEoln();
        ans.readEoln();
    }

    quitf(_ok, "correct");
}