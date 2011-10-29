#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class FuelConsumption {
public:
double maximalDistance(vector <int> velocities, vector <int> consumptions, int fuel) {
    vector <double> v;

    for(int i = 0; i < velocities.size(); i++) 
        v.push_back((double) consumptions[i] / (double)velocities[i]);
   
    vector <double>::iterator it = min_element(v.begin(), v.end());
    
    return (double)fuel*1.0 / *it;
}
};
