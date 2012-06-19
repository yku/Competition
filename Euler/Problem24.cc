#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    string s = "0123456789";
    int i = 1;
    do {
        if(i == 1000000) break;
        i++;
    }while(next_permutation(s.begin(), s.end()));
    cout << s << endl;

    return 0;
}

