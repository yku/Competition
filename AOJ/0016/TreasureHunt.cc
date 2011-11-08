#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void solve(vector<int>& steps, vector<int>& degrees)
{
    double x = 0.0, y = 0.0;
    double rad = 0.0;
    
    for(int i = 0; i < steps.size(); i++) {
        x += (double)steps[i]*sin(rad);  // x-y軸と角度の関係に注意
        y += (double)steps[i]*cos(rad); 
        rad += (double)degrees[i]*M_PI / 180.0;
    }
    cout << (int)x << endl << (int)y << endl;
}

int main()
{
    vector<int> steps, degrees;
    int s, d;
    char c;
    while(cin >> s >> c >> d, s || d) {
        steps.push_back(s);
        degrees.push_back(d);
    }
    solve(steps, degrees);

    return 0;
}
