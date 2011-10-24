#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class StoreCredit {
public:
string buy(int credit, vector<int> prices) {
    string ret;
    int i, j;
    const int size = prices.size();
   
    for(i = 0; i < size; i++) {
        for(j = i + 1; j < size; j++) {
            if( (prices[i] + prices[j]) == credit) {
                char buf[10];
                sprintf(buf, "%d %d", i+1, j+1);
                ret += buf;
                return ret;
            }
        }
    }
    return NULL;
}
};

void output(int n, string str)
{
   cout << "Case #" << n << ": " << str; 
}

int main()
{
    StoreCredit sc;
    vector<int> prices;
    vector<string> list;
    string ret;
    int cases, credit, lists;

    //ifstream ifs("A-small-practice.in");
    ifstream ifs("A-large-practice.in");
    string str;
    
    ifs >> str;
    cases = strtol(str.c_str(), NULL, 0);
    
    for(int i = 1; i <= cases; i++) {
        ifs >> str;
        credit = strtol(str.c_str(), NULL, 0);
        
        ifs >> str;
        lists = strtol(str.c_str(), NULL, 0);
        
        for(int j = 0; j < lists; j++) {
            ifs >> str;
            prices.push_back(strtol(str.c_str(), NULL, 0));
        }
        ret = sc.buy(credit, prices);
        output(i, ret);
        cout << endl;
        prices.clear();
    }

    return 0;
}
