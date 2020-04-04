#include <bits/stdc++.h>
using namespace std;

int shape[60][60], a, b, c;
bool row_safe[60][60], col_safe[60][60], ans;

void sol(int row, int col, int m) {
    if (row == a && col == a + 1 && m == b && !ans) {
        ans = true;
        cout << "Case #" << c << ": " << "POSSIBLE\n";
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= a; ++j) {
                cout << shape[i][j] << " ";
            }
          cout<<"\n";
        }
        return;
    } else if (row > a) {
        return;
    } else if (col > a) {
        sol(row + 1, 1, m);
    }
    for (int i = 1; i <= a && !ans; ++i) {
        if (!row_safe[row][i] && !col_safe[col][i]) {
            row_safe[row][i] = col_safe[col][i] = true;
            if (row == col) {
                m += i;
            }
            shape[row][col] = i;

            sol(row, col + 1, m);

            row_safe[row][i] = col_safe[col][i] = false;
            if (row == col) {
                m -= i;
            }
            shape[row][col] = 0;
        }
    }
}

int main() {
    int A;
    scanf(" %d", &A);
    for (c = 1; c <= A; ++c) {
        scanf(" %d %d", &a, &b);
        sol(1, 1, 0);
        if (!ans) {
            cout << "Case #" << c << ": " << "IMPOSSIBLE\n";
        }
        ans = false;
    }
    return 0;
}
