#include <iostream>
#include <vector>
using namespace std;

int solve(int M, int C, int W, vector<int>& A, vector<int>& B) {
    for (int i = C - 1; i >= 0; i--) {
        //cout << W << " " << A[i] << " " << B[i] << endl;
        // W$B$N0LCV$r$:$i$7$F$$$/(B!!
        
        // $B0l$DA0$N%7%c%C%U%k$G>e$K;}$C$F$3$i$l$?$N$J$i(B
        // $B$b$H$K$b$I$7$F$d$k(B.$B85$N0LCV$O(B1 -> Ai, 2 -> Ai+1...$B$J$N$G(B
        // 1 + Ai - 1 , 2 + Ai - 1, ..., W + Ai - 1
        if (W <= B[i]) {
            W += A[i] - 1;
        }
        // $B0l$DA0$N%7%c%C%U%k$G%9%i%$%9$5$l$k$H$3$m$h$j>e$K$$$?$J$i(B
        // -B$B$7$F$d$k$3$H$G>e$K$"$2$F$d$k(B
        else if (W <= A[i] + B[i] - 1) {
            W -= B[i];
        }
        // else { }
        // W$B$h$j$b>e$G%7%c%C%U%k$7$F$b(BW$B$K$O1F6A$J$7(B
    }
    return W;
}

int main() {
    int T, M, C, W, tmpA, tmpB;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> M >> C >> W;
        vector<int> A;
        vector<int> B;
        for (int j = 0; j < C; j++) {
            cin >> tmpA >> tmpB;
            A.push_back(tmpA);
            B.push_back(tmpB);
        }
        int answer = solve(M, C, W, A, B);
        cout << "Case #" << i << ": " << answer << endl;
    }
}

