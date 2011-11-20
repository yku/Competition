#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solve(vector<double> v, double v1, double v2)
{
    int ret = 0, distance = 0;
    double total_distance = 0.0;
    for(int i = 0; i < v.size(); i++) {
        total_distance += v[i]; 
    }

    double time = total_distance / (v1+v2); // 旅人算(単位はh)
    while(v1*time > distance) {
        distance += v[ret];
        ret++;
    }

    return ret;
}

int main()
{

    while(true) {
        vector<double> d;
        double v1, v2;
        char c;
       
        for(int i=0; i< 10; i++) {
            double t;
            cin >> t >> c; d.push_back(t);
        }
        cin >> v1 >> c >> v2;
        if(cin.eof()) break;
        
        cout << solve(d, v1, v2) << endl;
    }
    return 0;
}

