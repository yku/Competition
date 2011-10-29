#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class PalindromeDecoding {
public:
string decode(string code, vector <int> position, vector <int> length) {
    
    for(int i = 0; i < position.size(); i++) {
        int pos = position[i];
        int len = length[i];
        string insert_str = code.substr(pos, len);
        reverse(insert_str.begin(), insert_str.end());
        code.insert(pos+len, insert_str);
    }

    return code;
}
};
