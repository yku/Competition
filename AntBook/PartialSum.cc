#include <iostream>
#include <vector>

using namespace std;


bool dfs(vector<int>& a, int sum, int i, int k)
{
    if(a.size() == i) return sum == k;

    // a[i]を足す場合
    if(dfs(a, sum, i + 1, k + a[i])) return true;
    // a[i] を足さない場合
    if(dfs(a, sum, i + 1, k))        return true;
    return false;
}

bool solve(vector<int>& a, int sum)
{
    return dfs(a, sum, 0, 0);        
}

void test0()
{
    vector<int> a;
    bool ret;

    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    a.push_back(7);

    ret = solve(a, 13);
    if(ret) cout << "Yes" << endl;
    else    cout << "No" << endl;
}


void test1()
{
    vector<int> a;
    bool ret;

    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    a.push_back(7);

    ret = solve(a, 15);
    if(ret) cout << "Yes" << endl;
    else    cout << "No" << endl;
}

int main()
{
    test0();
    test1();
}
