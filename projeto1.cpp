#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Piece {
    int width, height, price;
};

int maximizeValue(int X, int Y, vector<Piece>& pieces) {
    int n = pieces.size();
    vector<vector<int>> dp(X + 1, vector<int>(Y + 1, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = pieces[i].width; j <= X; ++j) {
            for (int k = pieces[i].height; k <= Y; ++k) {   
                dp[j][k] = max(dp[j][k], dp[j - pieces[i].width][k - pieces[i].height] + pieces[i].price);
            }
        }
    }

    return dp[X][Y];
}

int main() {
    int X, Y;
    cin >> X >> Y;

    int n;
    cin >> n;

    vector<Piece> pieces(n);
    for (int i = 0; i < n; ++i) {
        cin >> pieces[i].width >> pieces[i].height >> pieces[i].price;
    }

    int result = maximizeValue(X, Y, pieces);
    cout << result << endl;

    return 0;
}
