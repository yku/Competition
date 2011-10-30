#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> hills;
    int hill;

    while(cin >> hill) {
        hills.push_back(hill);
    }

    sort(hills.begin(), hills.end(), greater<int>());

    for(int i = 0; i < 3; i++)
        cout << hills[i] << endl;

    return 0;
}
