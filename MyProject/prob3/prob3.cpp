#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string f;
  cin >> f;
  int n = f.length();

  vector<vector<int>> dp(10, vector<int>(n, 0));

  for (int i = 0; i < 10; ++i) {
    dp[i][0] = 1;
  }

  // Fill DP table
  for (int j = 1; j < n; ++j) {
    int current_f = f[j] - '0'; // Current digit in f
    for (int i = 0; i < 10; ++i) {
      int tmp = 2 * i - current_f;
      if (tmp - 1 >= 0 && tmp - 1 < 10)
        dp[i][j] += dp[tmp - 1][j - 1];
      if (tmp >= 0 && tmp < 10)
        dp[i][j] += dp[tmp][j - 1];
      if (tmp + 1 >= 0 && tmp + 1 < 10)
        dp[i][j] += dp[tmp + 1][j - 1];
    }
  }

  int total_ways = 0;
  for (int i = 0; i < 10; ++i) {
    total_ways += dp[i][n - 1];
  }

  cout << total_ways << endl;

  return 0;
}
