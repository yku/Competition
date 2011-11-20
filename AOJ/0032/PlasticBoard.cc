#include <iostream>

using namespace std;

int main()
{
    int a, b, diag, rectangle, diamond;
    char c;
    rectangle = diamond = 0;
    while(cin >> a >> c >> b >> c >> diag) {
        if(!(a+b>diag and b+diag>a and diag+a>b)) continue;
        if(diag*diag == (a*a + b*b)) rectangle++;
        if(a == b) diamond++;
    }
    cout << rectangle << endl << diamond << endl;
    return 0;
}
