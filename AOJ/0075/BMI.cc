#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool solve(int id, double w, double h)
{
    double bmi = (w / (h * h));
    if(bmi >= 25.0) return true;
    else            return false;
}

int main()
{
    int id;
    char comma;
    double w, h;
    while(cin >> id >> comma >> w >> comma >> h) {
        if(solve(id, w, h)) cout << id << endl;
    }
    return 0;
}

