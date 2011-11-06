#include <iostream>
#include <algorithm>

using namespace std;

/**
 * ref. http://www.interq.or.jp/moonstone/person/del/atari2.htm
 */
string solve(double x1, double y1, double x2, double y2, double x3, double y3, double xp, double yp)
{
    // 3点が同一直線上に存在するケース
    if((y1-y2)*x3+(x2-x1)*y3+x1*y2-x2*y1 == 0) return "NO";
    
    if(((y1-y2)*x3+(x2-x1)*y3+x1*y2-x2*y1)*((y1-y2)*xp+(x2-x1)*yp+x1*y2-x2*y1) < 0) return "NO";
    if(((y2-y3)*x1+(x3-x2)*y1+x2*y3-x3*y2)*((y2-y3)*xp+(x3-x2)*yp+x2*y3-x3*y2) < 0) return "NO";
    if(((y3-y1)*x2+(x1-x3)*y2+x3*y1-x1*y3)*((y3-y1)*xp+(x1-x3)*yp+x3*y1-x1*y3) < 0) return "NO";
    return "YES";
}

int main()
{
    double x1, y1, x2, y2, x3, y3, xp, yp;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp) 
        cout << solve(x1, y1, x2, y2, x3, y3, xp, yp) << endl;
    return 0;
}
