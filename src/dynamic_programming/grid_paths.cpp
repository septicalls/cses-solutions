#include <string>
#include <vector>
#include <iostream>

int main(void) {

    int n;
    std::cin >> n;
    std::vector<std::string> grid(n);

    for (int i = 0; i < n; i++) {
        std::cin >> grid[i];
    }

    std::vector<std::vector<long>> dp(n, std::vector<long> (n, 0));

    if (grid[n - 1][n - 1] != '*' && n > 1) {

        dp[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == '*') {
                    dp[i][j] = 0;
                    continue;
                }
                if (i + 1 < n) {
                    dp[i][j] += dp[i + 1][j] % 1'000'000'007;
                }
                if (j + 1 < n) {
                    dp[i][j] += dp[i][j + 1] % 1'000'000'007;
                }
            }
        }
    }

    std::cout << ((n > 1) ? dp[0][0] % 1'000'000'007 : ((grid[0][0] == '.') ? 1 : 0)) << '\n';

}