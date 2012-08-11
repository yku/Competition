#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;
typedef long long ll;

bool isTriangle(ll x)
{
    double n = (-1.0 + sqrt(1+8*x)) / 2.0;
    if(n == (int)n)
        return true;
    return false;
}

bool isPentagonal(ll x)
{
    double n = (1.0 + sqrt(1+24*x)) / 6.0;
    if(n == (int)n)
        return true;
    return false;
}
/**
 * Hexangle ⇒ Triangle
 * sqrt(1+8*x) は奇数なので2n+1と置き換えれば,
 * Triangleのときはnとなり、Hexangleのときは(n+1)/2となる。
 * Hexangleが成り立てばTriangleはnのみなので自動的に成り立つ
 */
bool isHexagonal(ll x)
{
    double n = (1.0 + sqrt(1+8*x)) / 4.0;
    if(n == (int)n)
        return true;
    return false;
}

ll getHexagonal(int n)
{
    return n * (2*n - 1);
}

int main()
{
    for(int i = 286; ; i++) {
        ll h = getHexagonal(i);
        if(isTriangle(h) and isPentagonal(h)) {
            cout << h << endl;
            break;
        }
    }
    return 0;
}
