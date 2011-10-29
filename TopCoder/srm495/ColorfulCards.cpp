#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class ColorfulCards {
public:
vector <int> theCards(int N, string colors) {
    int i, j;
    vector<int> v1, v2, ret;
    

    for(i = 1, j = 0; i <= N && j < colors.length(); i++) {
        if(colors[j] == 'R' && isPrime(i)) {
            v1.push_back(i);
            j++;
        }
        else if(colors[j] == 'B' && !isPrime(i)) {
            v1.push_back(i);
            j++;
        }
    }

    for(i = N, j = colors.length() - 1; i >= 1 && j >= 0; i--) {
        if(colors[j] == 'R' && isPrime(i)) {
            v2.push_back(i);
            j--;
        }
        else if(colors[j] == 'B' && !isPrime(i)) {
            v2.push_back(i);
            j--;
        }
    }

    reverse(v2.begin(), v2.end());

    for(i = 0; i < colors.length(); i++) {
        if(v1[i] == v2[i]) ret.push_back(v1[i]);
        else               ret.push_back(-1);
    }

    return ret;
}

bool isPrime(int n){
    int i;
    if(n < 2)
        return 0;
    else if(n == 2)
        return 1;
    if(n % 2 == 0)
        return 0;

    for(i = 3; i * i <= n; i += 2)
        if(n % i == 0)
              return false;
    return true;
}
};
