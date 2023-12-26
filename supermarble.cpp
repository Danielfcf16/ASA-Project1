#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int X, Y, n;
    if (scanf("%d %d %d", &X, &Y, &n) != 3) {
        return 1; // Exit the program if the input is not read correctly
    }

    vector<int> a(n), b(n), p(n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d %d %d", &a[i], &b[i], &p[i]) != 3) {
            return 1; // Exit the program if the input is not read correctly
        }
    }

    // Create a DP table initialized to 0, to store the maximum value for each sub-slab size.
    vector<vector<int>> dp(X + 1, vector<int>(Y + 1, 0)); 

    // Initialize the DP table with the value of the pieces that fit exactly into the marble slab
    for (int i = 0; i < n; ++i) {
        if (a[i] <= X && b[i] <= Y) {
            dp[a[i]][b[i]] = max(dp[a[i]][b[i]], p[i]);
        }
        if (b[i] <= X && a[i] <= Y) {
            dp[b[i]][a[i]] = max(dp[b[i]][a[i]], p[i]);
        }
    }

    // Fill the DP table by considering all possible horizontal and vertical cuts
    for (int i = 1; i <= X; ++i) {
        for (int j = 1; j <= Y; ++j) {
            // Check for horizontal cuts
            for (int cut = 1; cut < i; ++cut) {
                dp[i][j] = max(dp[i][j], dp[cut][j] + dp[i - cut][j]);
            }
            // Check for vertical cuts
            for (int cut = 1; cut < j; ++cut) {
                dp[i][j] = max(dp[i][j], dp[i][cut] + dp[i][j - cut]);
            }
        }
    }

    printf("%d\n", dp[X][Y]); // Output the maximum value that can be obtained from the entire marble slab

    return 0;
}
