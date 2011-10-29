#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Alliteration {
public:
int count(vector <string> words) {
    int ret = 0;
    map<char, int> m;
    
    for(int i = 0; i < words.size(); i++) {
        string str = words[i];
        if(str.length() <= 1) continue;
        char c = toupper(str[0]);
        m[c]++;
    }
    
    map<char, int>::iterator it = m.begin();
    while( it != m.end() )
    {
        if( (*it).second > 1) ret++;
        it++;
    }

    return ret;
}
};
