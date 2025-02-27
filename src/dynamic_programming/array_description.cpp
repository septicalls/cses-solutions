#include <vector>
#include <numeric>
#include <iostream>

const int MOD = 1e9 + 7;

int main(void) {

    int n, m;
    std::cin >> n >> m;

    std::vector<int> x(n);

    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::vector<std::vector<long>> dp(n + 1, std::vector<long> (m + 1, 0L));

    if (x[0] != 0) {
        dp[1][x[0]] = 1L;
    } else {
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1L;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (x[i - 1] != 0) {
            int y = x[i - 1];
            dp[i][y] = dp[i - 1][y];
            if (y - 1 >= 1) dp[i][y] += dp[i - 1][y - 1];
            if (y + 1 <= m) dp[i][y] += dp[i - 1][y + 1];
            dp[i][y] %= MOD;
        } else {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 1) dp[i][j] += dp[i - 1][j - 1];
                if (j + 1 <= m) dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
        }
    }

    std::cout << std::accumulate(dp[n].cbegin(), dp[n].cend(), 0L, [](long acc, long ele){
        return (acc + ele) % MOD;
    }) << '\n';

}