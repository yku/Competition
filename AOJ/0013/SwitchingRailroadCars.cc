#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve(vector<int>& v)
{
    stack<int> st;

    for(int i = 0; i < v.size(); i++) {
        if(v[i] == 0) { cout << st.top() << endl; st.pop(); }
        else          st.push(v[i]);
    }
}

int main()
{
    vector<int> v;
    int n;
    while(cin >> n) 
        v.push_back(n);
    solve(v);
    
    return 0;
}
