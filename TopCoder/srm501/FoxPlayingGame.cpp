#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Reference: http://techtipshoge.blogspot.com/2011/03/srm-brushup-foxplayinggame-501-div2.html
 * $BJ}?K(B: $B@5Ii$K4X$o$i$:(BscoreA$B$OA4ItB-$9(B
 *       scoreB$B$O(B4$B$D$NA*Br;h$,$"$k(B
 *        1. $B3]$1$k$H>.$5$/$J$k(B(-1.0 < scoreB < 1.0)$B$NHO0O(B => $B3]$1$J$$$N$,$h$$(B
 *        2. $B3]$1$l$P3]$1$k$[$IBg$-$/$J$k(B => $BA4It3]$1$k(B
 *        3. 2.$B$H4pK\F1$8$@$,!"Id9f$N4X78$G3]$1$k2s?t$r0l$D8:$i$9(B => ($BA4It(B-1)$B3]$1$k(B
 *        4. 1$B2s$@$13]$1$k!#3]$1$k$H@dBPCM$O>.$5$/$J$k$,Id9f5UE>$7$F@5$K$J$k(B => 1$B2s$@$13]$1$k(B
 */ 
class FoxPlayingGame {
public:
double theMax(int nA, int nB, int paramA, int paramB) {
    double scoreA = paramA / 1000.0;
    double scoreB = paramB / 1000.0;

    if(nA == 0) return 0;
    if(nB == 0) return nA * scoreA;

    double ret = nA * scoreA;
    ret = max(ret, nA * scoreA * pow(scoreB, nB));
    ret = max(ret, nA * scoreA * pow(scoreB, nB-1));
    ret = max(ret, nA * scoreA * scoreB);

    return ret;

}



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
