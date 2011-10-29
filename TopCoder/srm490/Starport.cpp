#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Starport {
public:
double getExpectedTime(int N, int M) {
    int arrived[N+1], teleported[M+1];
    double wait_time = 0.0;

    memset(arrived, 0, sizeof(arrived));
    memset(teleported, 0, sizeof(teleported));

    for(int i = 0; i < N+1; i++) arrived[i] += i * M;
    for(int i = 0; i < M+1; i++) teleported[i] += i * N;

    for(int i = 0; i < N+1; i++)
         wait_time += getWaitTime(teleported, 0, arrived[i]);
    
    return (double)(wait_time / N);
}

int getWaitTime(int *t, int i, int a) {
    int diff = *(t+i) - a;
    if (diff >= 0) { 
        return diff;
    } else {
        return getWaitTime(t, i + 1, a);
    }
}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
