#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while(getline(cin, s)) {
        for(int i = 0; i < s.length(); i++) {
            if('a' <= s[i] and s[i] <= 'z')
                s[i] = toupper(s[i]);
        }
        cout << s << endl;
    }
    return 0;
}
