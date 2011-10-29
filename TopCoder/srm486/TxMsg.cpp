#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TxMsg {
public:
string getMessage(string original) {
    istringstream iss(original);
    vector<string> v((istream_iterator<string>(iss)),
                      istream_iterator<string>());
    vector<string>::iterator it = v.begin();
    while(it != v.end()) {
        cout << *it << endl;
        it++;
    }
/*
    for(w : words){
        type = getType(w);
        switch(type){
            case 0: // only vowel
                buf = w;
                break;
            case 1:
                buf = transform(w);
                break;
        }
        ret += buf;
    }
    return ltrim(buf);
    */
    return "hello";
}
/*
int getType(string w)
{
    int i;
    int size = w.size();
    for(i = 0; i < size; i++) {
        char c = w[i];
        if (w != 'a' && w != 'i' && w != 'u' && w != 'e' && w != 'o') {
            return 1;
        }
    }
    return 0;
}*/
};

int main()
{
    TxMsg* tm = new TxMsg();
    tm->getMessage("i love please");

}
