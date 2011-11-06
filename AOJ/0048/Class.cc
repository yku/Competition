#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

string solve(double w)
{
    if(w <= 48.00) return "light fly";
    if(48.00 < w and w <= 51.00) return "fly";
    if(51.00 < w and w <= 54.00) return "bantam";
    if(54.00 < w and w <= 57.00) return "feather";
    if(57.00 < w and w <= 60.00) return "light";
    if(60.00 < w and w <= 64.00) return "light welter";
    if(64.00 < w and w <= 69.00) return "welter";
    if(69.00 < w and w <= 75.00) return "light middle";
    if(75.00 < w and w <= 81.00) return "middle";
    if(81.00 < w and w <= 91.00) return "light heavy";
    if(w >= 91.00) return "heavy";
}

int main()
{
    double w;
    while(cin >> w) 
        cout << solve(w) << endl;

    return 0;
}

