#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;
typedef long long ll;

int solve(int n)
{
    int ret = 1;

    int a, b;
    // Triangle Number は (n*(n+1)) / 2 で求められる。
    // divisor の数は素因数分解したときの指数の組み合わせの数で求まる
    //
    // nとn+1が互いに素なのを利用して計算量を削減
    // 互いに素なのでnとn+1は素因数が同じものがない => 独立して指数をもとめられる
    // 計算の都合上 a > b とする
    if(n & 1) { a = n; b = (n+1)/2; }
    else { a = n+1; b = n/2; }
    
    int t = a;
    map<int, int> dict;
    for(int i = 3; i <= t && (a || b); ) {
        if(a % i == 0) {
            dict[i]++;
            a /= i;
        }
        else if(b % i == 0) {
            dict[i]++;
            b /= i;
        }
        else i += 2;
    }
    
    while(b != 1) {
        dict[2]++;
        b /= 2;
    }
    map<int, int>::iterator it = dict.begin();
    while(it != dict.end()) {
        //cout << (*it).first << ":" << (*it).second << endl;
        ret *= ((*it).second + 1); 
        it++;
    }
    return ret;
}

int main()
{
    int i = 1;
    while(true) { 
        if(solve(i) > 500) {
            cout << (i*(i+1)/2) << endl;
            break;
        }
        i++;
    }
    return 0;
}

