#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]){
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    
    int pans = ouf.readDouble(-2'000'000, 2'000'000, "participant");
    int jans = ans.readDouble(-2'000'000, 2'000'000, "jury");

    if(pans==jans) quitf(_ok, "correct");
    else quitf(_wa, "wrong answer");
    
}